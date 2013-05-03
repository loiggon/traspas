int anyIntroduit;
boolean anyIntTraspas;

void setup()
{
  Serial.begin(9600);
  Serial.println("Introduieix un any: ");
}

void loop()
{
  while(Serial.available()>0)
  {
    anyIntroduit = Serial.parseInt();
    if(Serial.read() == '\n')
    {
      anyIntTraspas = traspas(anyIntroduit);
      if(anyIntTraspas == true)
      {
        Serial.println("Lany introduit es de traspas");
      }
      else
      {
        Serial.println("Lany introduit no es de traspas");
      }
      Serial.println("Introduieix un any: ");
    }    
  }   
}

boolean traspas (int any)
{
  boolean anyTraspas = false;
  int iniciAny = any / 100;
  int fiAny = any % 100;
  
  if ((fiAny != 0) && (fiAny % 4 == 0))
  {
    anyTraspas = true;
  }
  else if ((fiAny == 0) && (iniciAny % 4 == 0))
  {
    anyTraspas = true;
  }
  else
  {
    anyTraspas = false;
  }
  return(anyTraspas);
}
