
//Row 1, colloum 1
int pin11 = 0;
//Row 2, colloum 1
int pin21 = 1;
//Row 3, colloum 1
int pin31 = 2;
//Row 3, colloum 2
int pin32 = 3;
//Row 2, colloum 2
int pin22 = 4;
//Row 1, colloum 2
int pin12 = 5;

//Player pins
int pos1 = 8;
int pos2 = 9;

//ButtonPin
int button = 11;

//LosePin
int losePin = 13; 

//The array to handle the leds
int ledArray[3][2]; 

//Create a random
int randomNum;
//Other variables
int timer;
bool rightDanger = false;
bool leftDanger = false;
bool lose = false;

int rowsPassed;

void setup()
{
  pinMode(pin11, OUTPUT);
  digitalWrite(pin11, HIGH);
  pinMode(pin21, OUTPUT);
  digitalWrite(pin21, HIGH);
  pinMode(pin31, OUTPUT);
  digitalWrite(pin31, HIGH);
  pinMode(pin32, OUTPUT);
  digitalWrite(pin32, HIGH);
  pinMode(pin22, OUTPUT);
  digitalWrite(pin22, HIGH);
  pinMode(pin12, OUTPUT);
  digitalWrite(pin12, HIGH);
  pinMode(pos1, OUTPUT);
  digitalWrite(pos1, HIGH);
  pinMode(pos2, OUTPUT);
  digitalWrite(pos2, HIGH);
  pinMode(button, INPUT_PULLUP);
  pinMode(losePin, OUTPUT);
  digitalWrite(losePin, HIGH);
  //Serial.begin(115200);
  for(int x = 0; x < 3; x++)
  {
     for(int y = 0; y < 3;y++)
    {
     ledArray[x][y] = 0;
    } 
  }
  
  timer = 0;
  lose = false;
  rowsPassed = 0;
}

void loop()
{
  timer++;
  
  if(lose == false)
  {
   digitalWrite(losePin, LOW); 
   
  }
  else if(lose == true)
  {
   digitalWrite(losePin, HIGH); 
   //turnOnAll();

  }
  
  
  
  
  if(lose == false)
  {
    manageObsticles();
  
    if(digitalRead(button) == true)
    {
      digitalWrite(pos2, HIGH);
      digitalWrite(pos1, LOW);
      if(leftDanger == true)
      {
        lose = true;
      }
    }
    else if(digitalRead(button) == false)
    {
      digitalWrite(pos2, LOW);
      digitalWrite(pos1, HIGH);
      if(rightDanger == true)
      {
        lose = true;
      }
    }
    
    rightDanger = false;
    leftDanger = false;
  }
  else if(lose == true)
  {
   if(timer % 400 == 0)
  {
   turnOffAll();
  } 
  if(timer % 250 == 0)
  {
   turnOnAll(); 
  }
  if(timer % 30000 == 0)
  {
    setup();
  
  
  }
  
  }

  
  
}

void manageObsticles()
{
  if( ledArray[0][0] >= 1)
  {
   digitalWrite(pin11, HIGH); 
  }
  else
    digitalWrite(pin11, LOW); 
    if( ledArray[1][0] >= 1)
  {
   digitalWrite(pin21, HIGH); 
  }
  else
    digitalWrite(pin21, LOW); 
    if( ledArray[2][0] >= 1)
  {
   digitalWrite(pin31, HIGH); 
  }
  else
    digitalWrite(pin31, LOW); 
    if( ledArray[0][1] >= 1)
  {
   digitalWrite(pin12, HIGH); 
  }
  else
    digitalWrite(pin12, LOW); 
    if( ledArray[1][1] >= 1)
  {
   digitalWrite(pin22, HIGH); 
  }
  else
    digitalWrite(pin22, LOW); 
    if( ledArray[2][1] >= 1)
  {
   digitalWrite(pin32, HIGH); 
  }
  else
    digitalWrite(pin32, LOW); 
    if(rowsPassed > 50)
    rowsPassed = 50;
    if(timer == (10000 - rowsPassed * 100) )
    {
     moveDown(); 
     timer = 0;
     randomNum = random(2);
     if(randomNum == 0)
      {
       ledArray[0][0] = 1; 
      }
      else
      ledArray[0][1] = 1;
    }
    
}


void moveDown()
{
 for(int x = 2; x >= 0; x--)
  {
     for(int y = 1; y >= 0; y--)
     {
      if(ledArray[x][y] > 0)
      {
         if(x < 2)
        {
         ledArray[x + 1][y] = ledArray[x][y];
         ledArray[x][y] = 0;
         
        }
        else
        {
          if(ledArray[x][y] == 1)
          {
           if(y == 0)
           {
            leftDanger = false;
            rightDanger = true;
           } 
           if( y == 1)
           {
            rightDanger = false; 
            leftDanger = true;
           }
          }
         ledArray[x][y] = 0;
         rowsPassed++;
         
        } 
      }
     }
  } 
}

void turnOnAll()
{
   
  digitalWrite(pin11, HIGH);
  
  digitalWrite(pin21, HIGH);
  
  digitalWrite(pin31, HIGH);
  
  digitalWrite(pin32, HIGH);
  
  digitalWrite(pin22, HIGH);
  
  digitalWrite(pin12, HIGH);
  
  digitalWrite(pos1, HIGH);
  
  digitalWrite(pos2, HIGH);
  
  digitalWrite(losePin, HIGH); 
}

void turnOffAll()
{  
  digitalWrite(pin11, LOW);
  
  digitalWrite(pin21, LOW);
  
  digitalWrite(pin31, LOW);
  
  digitalWrite(pin32, LOW);
  
  digitalWrite(pin22, LOW);
  
  digitalWrite(pin12, LOW);
  
  digitalWrite(pos1, LOW);
  
  digitalWrite(pos2, LOW);
  
  digitalWrite(losePin, LOW); 
}


