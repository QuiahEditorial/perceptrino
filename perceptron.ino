                                          // Sea una red con las propiedades:
float u = 0.5;                            // umbral
float r = 0.1;                            // razon de aprendizaje
float b = 0;                              // bias f_0(x) = 0
const int d = 3;                          // dimensión de las observaciones
const int n = 4;                          // cantidad de observaciones

float W[d] =      {0,0,0};                // pesos iniciales
float A[n][d] = { {1,0,0},                // arreglo de entrenamiento
                  {1,0,1},
                  {1,1,0},
                  {1,1,1} };
float Z[n] =      {1,1,1,0};              // salidas esperadas
float C[d] =      {0,0,0};                // clasificación
float D;                                  // corrección
float R;                                  // red
float E;                                  // error

float S;                                  // suma
int i,j;                                  // contadores
int k = 8;                                // teorema del perceptrón

void setup()
{
Serial.begin(2000000);
}

void loop()
{
for(k=0;k<=8;k++){for(j=0;j<=3;j++){for(i=0;i<=d-1;i++){
  C[i]=W[i]*A[j][i];S+=C[i];} //Serial.print(S); Serial.print(" "); // S = \sum_{i=0}^{i=d} w_i x_{ji}
  if(S>u){R=1;} else{R=0;}    //Serial.print(R); Serial.print(" "); // \phi(x) = cases 1,w^T x > u \\ 0, w^T x \leq u
  S=0; E = Z[j]-R;            //Serial.print(E); Serial.print(" "); // e = Z-R
  D = r*E;                    //Serial.print(D); Serial.print(" "); // W_i = W_i + x_i ( r e )
for(i=0;i<=2;i++) {W[i]+=A[j][i]*D; Serial.print(W[i]);Serial.print(" ");}
                   Serial.write(10);
                  }
                   Serial.println("--------------");
                  }
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
