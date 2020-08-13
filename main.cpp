
*//*0A (15., 18., 15), B (33, -87, -99), C (69, 27, -151), D (10.9, 55, -38). */

#include <stdio.h>
#include "myvector3d.h"
int main()
{
    MyVector3D   A (15,18,15), B (33,-87,-99), C (69,27,-151), D (10.9,55,-38);

    printf("\n\n\tProgram started\n");

    MyVector3D AB=B-A,
               AC=C-A,
               AD=D-A,
               BC=C-B,
               BD=D-B,
               CD=D-C;

 /* printf("\n\tAB "); PrintMyVector3D(AB);
    printf("\n\tAC "); PrintMyVector3D(AC);
    printf("\n\tAD "); PrintMyVector3D(AD);
    printf("\n\tBC "); PrintMyVector3D(BC);
    printf("\n\tBD "); PrintMyVector3D(BD);
    printf("\n\tCD "); PrintMyVector3D(CD);*/

   MyVector3D  n=AB*AC,
               n1=AD*AC,
               n2=BD*BC,
               n3=AD*AB;

   printf("\n\n\tAB*AC= "); PrintMyVector3D(n);
   printf("\n\tAD*AC= "); PrintMyVector3D(n1);
   printf("\n\tBD*BC= "); PrintMyVector3D(n2);
   printf("\n\tAD*AD= "); PrintMyVector3D(n3);

   double *S=new double[4];

   S[0]=(n.norm())/2.;
   S[1]=(n1.norm())/2.;
   S[2]=(n2.norm())/2.;
   S[3]=(n3.norm())/2.;

   printf("\n\n\tSabc=%lg",S[0]);
   printf("\n\tSadc=%lg",S[1]);
   printf("\n\tSabd=%lg",S[2]);
   printf("\n\tSbdc=%lg",S[3]);

   for (int i = 0; i < 4 - 1; i++) {
           for (int j = 0; j < 4 - i - 1; j++) {
               if (S[j] < S[j + 1]) {

                   double temp = S[j];
                   S[j] = S[j + 1];
                   S[j + 1] = temp;
               }
           }
       }

    printf("\n\n\tSmax=%g",S[0]);
    printf("\n\n\tPress ENTER\n");
    getchar();

    return 0;
}
