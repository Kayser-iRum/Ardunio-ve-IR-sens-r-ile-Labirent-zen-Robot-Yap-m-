// ır sensörleri ile yapılan deneme
int onirpin = 11 ; // on kızıl ötesi
int solirpin = 10; // sol kızıl ötesi
int sagirpin = 12 ; // sağ kızıl ötesi
int sagsolbos = 0;
int teksayi[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
int ciftsayi[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
#define MotorLE 5 // Sol motor hız pini
#define MotorRE 6 // Sağ motor hız pini
#define MotorL1 4 // Sol motor pin 1
#define MotorL2 3 // Sol motor pin 2
#define MotorR1 8 //Sağ motor pin 1
#define MotorR2 9 // Sağ motor pin 2
int donnus ;
void setup() 
{
pinMode(onirpin , INPUT);
pinMode(solirpin , INPUT);
pinMode(sagirpin , INPUT);
pinMode(MotorLE, OUTPUT);
pinMode(MotorRE, OUTPUT);
pinMode(MotorL1, OUTPUT);
pinMode(MotorL2, OUTPUT);
pinMode(MotorR1, OUTPUT);
pinMode(MotorR2, OUTPUT);
Serial.begin(9600);
}

void loop() 
{
  int onir , solir , sagir ;
  onir = (digitalRead(onirpin));
  solir = (digitalRead(solirpin));
  sagir=(digitalRead(sagirpin));
    if((onir == 1 && sagir == 0 && solir == 0) || (onir == 1 && sagir == 0 && solir == 1) || (onir == 1 && sagir == 1 && solir == 0) || (onir == 1 && sagir == 1 && solir == 1) )
  {
    ileri();
    Serial.println("ileri");
  }
  if(onir == 0 && sagir == 0 && solir == 1)
  {
    sol ();
    Serial.println("sol");
  }
  if (onir == 0 && sagir == 1 && solir == 0)
  {
   sag(); 
   Serial.println("sag");
  }
  if (onir == 0 && sagir == 0 && solir == 0)
  {
    donus();
    Serial.println("donus");
  }
    if(onir == 0 && sagir == 1 && solir == 1){
//      dur();
//      donnus++;
//      for(int i = 0;i<8;i++){
//        if(donnus == teksayi[i]) {sol(); Serial.println("sol2");}
//        if(donnus == ciftsayi[i]) {sag(); Serial.println("sag2");}
//      }
//     
    dur();
    donnus++;
    if(donnus/2 == 0) {sag(); Serial.println("sağ2"); delay(300);}
    else {sol();Serial.println("sol2");delay(300);}}
  }
////  if(onir == 1 && sagir == 1 && solir == 1){
////    dur();
////    }
////  solir = (digitalRead(solirpin));
//////  Serial.println(solir);
//////  delay(1000);
////  if(solir == 1 && sagir == 0 && onir == 0 )
////  {
////  sag();
////  //Serial.println("sola dönüş");
////  //delay(1000);
////  }
////  onir = (digitalRead(onirpin));
////  //Serial.println(onir);
////  //delay(1000);
////    if (solir == 1 && sagir == 1 && onir == 0 )
////{
////    sol ();
////}
////  if (onir == 1)
////  {
////  ileri();
////  //Serial.println("ileri dönüş");
////  //delay(1000);
////  }
////  sagir = (digitalRead(sagirpin));
////  //Serial.println(sagir);
////  //delay(1000);
////  if (sagir == 1 && onir == 0 && solir == 0)
////  {
////  sol();
////  //Serial.println("sağa dönüş");
////  //delay(1000);
////  }
//// 
////  else if ( solir == 0 && onir == 0 && sagir == 0 )
////{
//// donus();
//////Serial.println("dönüş");
//////  delay(1000);
////}
////
////  else if (solir = 0 && sagir == 0 && onir == 1)
////  {
////    ileri ();
////  }


void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 65); // Sağ motorun hızı 150
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 65); // Sol motorun hızı 150 
  
}
void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 65); // Sağ motorun hızı 0 (Motor duruyor)
  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 65); // Sol motorun hızı 150
  
}
//void geri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
//  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi pasif
//  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi aktif
//  analogWrite(MotorRE, 100); // Sağ motorun hızı 150
//  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
//  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
//  analogWrite(MotorLE, 100); // Sol motorun hızı 150
//}
void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 65); // Sağ motorun hızı 0 (Motor duruyor)
  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 65); // Sol motorun hızı 150
  
}

void dur(){
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 0);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 0);
 
}

void donus()
{
digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 65);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE,65 );

}
