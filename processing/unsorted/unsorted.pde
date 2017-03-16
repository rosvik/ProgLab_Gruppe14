int[] BtnSize = {20,20,100,30};
String BtnText = "Woo";

int[] TxtSize = {20,60,200,30};
String TxtString = "empty";
int count = 0;

void setup() {
  size(400,600);
  setCanvas(400,600);              // Canvas size is 400 x 600 pixels.
  background(128);            // Background color is gray (128,128,128).
  stroke(0);                  // Stroke color is black (0,0,0)
}

//void draw() {
//  stroke(0);
//  fill(255);
//  rect(10,10,380,280);
  
//  drawButton(BtnSize,BtnText);
//  drawText(TxtSize,TxtString);
  
//}


//void mousePressed() {
//  if (mouseInside(BtnSize)) {
//    count++;
//    TxtString = "" + count;
//  }  
//}