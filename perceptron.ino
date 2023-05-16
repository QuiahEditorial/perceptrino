// Por Roberto A. Zavala
// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼    : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

                                          // Sea una red con las propiedades:
float u = 0.5;                            // umbral
float r = 0.1;                            // razon de aprendizaje
float b = 0;                              // bias f_0(x) = 0
const int d = 3;                          // dimensión de las observaciones
const int n = 4;                          // cantidad de observaciones

float W[d] =      {0,0,0};                // pesos iniciales
float A[n][d] = { {1,0,0},                // Sea el arreglo de entrenamiento
                  {1,0,1},
                  {1,1,0},
                  {1,1,1} };
float Z[n] =      {1,1,1,0};              // salidas etiquetadas manualmente
float C[d] =      {0,0,0};                // clasificación
float D;                                  // corrección
float R;                                  // red
float E;                                  // error
float e;                                  // errores

float S;//[4] =      {0,0,0,0};           // sumas
int i,j,k;                                // contadores

void setup()
{
Serial.begin(2000000);
}

void loop()
{
iteracion:
e=0;
for(j=0;j<=3;j++){for(i=0;i<=d-1;i++){
  C[i]=W[i]*A[j][i];S+=C[i];}  //Serial.print(S); Serial.print(" "); // S = \sum_{i=0}^{i=d} w_i x_{ji}
  if(S>u){R=1;} else{R=0;} //Serial.print(R); Serial.print(" "); // \phi(x) = cases 1,w^T x > u \\ 0, w^T x \leq u
  S=0; E = Z[j]-R;             //Serial.print(E); Serial.print(" "); // e = Z-R
  if (E==0){ } else{e++;}
  D = r*E;                     //Serial.print(D); Serial.print(" "); // W_i = W_i + x_i ( r e )
for(i=0;i<=2;i++) {W[i]+=A[j][i]*D; Serial.print(W[i]);Serial.print(" ");}
                   Serial.write(10);
                 }
                   Serial.println("--------------");
if (e>0){goto iteracion;} else{Serial.println("Ok");}
pctn();
delay(10);
exit(0);
}

void pctn()
{
Serial.println("Entrada         | Salida");
for(j=0;j<=3;j++){for(i=0;i<=d-1;i++){
  Serial.print(A[j][i]);   Serial.write(" ");
  S+=W[i]*A[j][i];
  }
  Serial.print(" | ");
  if(S>u){R=1;} else{R=0;} Serial.print(R); S=0; Serial.write(10);
  }
}
