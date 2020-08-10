class rmatrix
{

public:
    int row, col;
    double **a;

    rmatrix (int r=1, int c=1);
    rmatrix (rmatrix & m);
    rmatrix (int, int, double **);
    ~rmatrix();

    rmatrix & operator = (rmatrix & m);
    rmatrix  operator + (rmatrix & m);
    rmatrix  operator - (rmatrix & m);
    rmatrix  operator * (rmatrix & m);
    rmatrix  operator * (double l);
    rmatrix transpose (void);
    double & operator ()(int, int);
    friend ostream & operator << (ostream & out, rmatrix & m);
    friend istream & operator >> (istream & in, rmatrix & m);

};

class sqmatrix : public rmatrix
{
public:
    sqmatrix (int);
    sqmatrix (sqmatrix &);
    sqmatrix(int, double **);
    sqmatrix minor(int, int);
    int sign(int, int);
    double det();
    sqmatrix inverse();
};

class vector : public rmatrix
{
    int size;
    double * w;
public:
    vector(int);
    vector(vector &);
    vector(int, double *);
    double mod();
    double operator *(vector &);
};

//------------- прямоугольные матрицы-----------//
rmatrix :: rmatrix (int r, int c)
{
    a=new double * [row=r];
    for (int i=0; i<row; i++)
        a[i]=new double [col=c];
}

rmatrix :: rmatrix (rmatrix & m)
{
    a=new double *[row=m.row];
    for (int k=0; k<row; k++)
        a[k]=new double [col=m.col];
    for (int i=0; i<m.row; i++)
        for (int j=0; j<m.col; j++)
            a[i][j]=m(i,j);
}
rmatrix :: rmatrix (int r, int c, double **m)
{
    a= new double *[row=r];
    for (int i=0; i<row; i++)
        a[i]=new double [col=c];
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            a[i][j]=m[i][j];
}
rmatrix :: ~rmatrix()
{
    for (int i=0; i<row; i++)
        delete [] a[i];
    delete [] a;
}
double & rmatrix :: operator () (int i, int j)
{
    return a[i][j];
}

rmatrix & rmatrix :: operator = (rmatrix & m)
{
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            (*this)(i,j)=m(i,j);
    return (*this);
}

rmatrix rmatrix ::transpose()
{
    rmatrix temp(col, row);

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            temp(j, i)=(*this)(i, j);
    return temp;
}

rmatrix rmatrix :: operator + (rmatrix & m)
{
    if (row==m.row && col==m.col)
    {
        rmatrix temp(m.row, m.col);
        for (int i=0; i<m.row; i++)
            for (int j=0; j<m.col; j++)
                temp(i,j)=(*this)(i,j)+m(i,j);
        return temp;
    }
    else
    {
        cout<<"error rmatrix: operator + : razmernost' matriz ne sovpadaet!"<<endl;
        return 0;
    }
}
rmatrix rmatrix :: operator - (rmatrix & m)
{
    if (row==m.row && col==m.col)
    {
        rmatrix temp(row,col);
        for (int i=0; i<m.row; i++)
            for (int j=0; j<m.col; j++)
                temp(i,j)=(*this)(i,j)-m(i,j);
        return temp;
    }
    else
    {
        cout<<"error rmatrix: operator - : razmernost' matriz ne sovpadaet!"<<endl;
        return 0;
    }
}
rmatrix rmatrix :: operator * (rmatrix & m)
{
    if (col==m.row)
    {
        rmatrix temp(row, m.col);
        for (int i=0; i<row; i++)
            for (int j=0; j<m.col; j++)
            {
                temp(i,j)=0.0;
                for (int k=0; k<col; k++)
                    temp(i,j)+=(*this)(i,k)*m(k,j);
            }
        return temp;
    }
    else
    {
        cout<<"error rmatrix: operator * : oshibka v razmernosti matriz"<<endl;
        return 0;
    }
}

rmatrix rmatrix :: operator * (double l)
{
    rmatrix temp(row,col);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            temp(i,j)=(*this)(i,j)*l;
    return temp;
}

ostream & operator << (ostream & out, rmatrix & m)
{
    for (int i=0; i<m.row; i++)
    {
        for (int j=0; j<m.col; j++)
        {
            out.width(5);
            out << m(i,j);
        }
        out << endl;
    }
    return out;
}

istream & operator >> (istream & in, rmatrix & m)
{
    for (int i=0; i<m.row; i++)
    for (int j=0; j<m.col; j++)
        in >> m(i,j);
    return in;
}

//---------------- квадратные матрицы -------------------//

sqmatrix :: sqmatrix(int row):rmatrix(row, row) {;}

sqmatrix :: sqmatrix(sqmatrix & m): rmatrix(m)
{
    row=m.row;
    a=new double * [row];
    for(int i=0;i<col;i++)
        a[i]=new double [row];
}

sqmatrix :: sqmatrix(int r, double **m):rmatrix(r, r, m) {;}

sqmatrix sqmatrix :: minor(int i, int j)
{
    sqmatrix temp(row-1);
    for(int k=0;k<row-1;k++)
        for(int l=0;l<row-1;l++)
            temp(k, l)=(*this)(k<i ? k:k+1, l<j ? l:l+1);

    return sqmatrix(row-1, temp.a);
}

int sqmatrix :: sign(int i, int j)
{
    return ((i+j)%2 == 0) ? 1:-1;
}

double sqmatrix :: det()
{
    double d;
    if(row==1)
        return (*this)(0, 0);
    else
    {
        d=0.0;
        for(int i=0;i<row;i++)
            d+=sign(0, i)*(*this)(0, i)*minor(0, i).det();
    }
    return d;
}

sqmatrix sqmatrix ::inverse()
{
    double d=(*this).det();
    sqmatrix t(row);
    if(d==0)
    {
        cout<<"det=0, obratnoi matrici ne sushestvuet!"<<endl;
        exit(1);
    }
    else
    {
        for(int i=0;i<row;i++)
            for(int j=0;j<row;j++)
                t(j, i)=sign(i, j)*minor(i, j).det()/d;
    }
    return sqmatrix(row, t.a);
}

//------------------- класс вектор -------------------------//

vector :: vector(int s):rmatrix(1, s){col=s;}

vector :: vector(vector & v):rmatrix(v)
{
    col=v.size;
    w=new double[size];
}

vector :: vector(int s, double * mas):rmatrix(1, s, &mas) {col=s;}

double vector :: mod()
{
    double d=0.0;
    for(int i=0;i<(*this).col;i++)
        d+=(*this)(0, i)*(*this)(0,  i);
    return sqrt(d);
}

double vector :: operator *(vector & v)
{
    double res=0.0;
    if((*this).col != v.col)
    {
        cout<<"error: vector: skaljarnoe pr. : oshibka v razmere"<<endl;
        exit(1);
    }
    else
    {
        for(int i=0;i<(*this).col;i++)
            res+=(*this)(0, i)*v(0, i);
    }
    return res;
}
