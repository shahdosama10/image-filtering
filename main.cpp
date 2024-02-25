#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];

void load_image();
void save_image();
void load_image_1();
void image_inverter();
void save_image_1();
void black_white_image();
void merge_filter();
void image_rotate();
void lighten();
void darken();
void flip_image_left_right();
void flip_image_upside_down();
void mirror_1();
void mirror_2();
void mirror_3();
void mirror_4();
void blur_image();
void shrink_image();
void shrink_image_2();
void shrink_image_3();

int main() {
    int choice;
    int operation;
    bool checker = true;
    char reuse;
    while (checker){
        cout << "1.Black and White" << endl << "2.Invert" << endl << "3.Merge" << endl << "4.Flip"
             << endl << "5.Rotate" << endl << "6.Darken and Lighten" << endl << "7.Detect Edges"<< endl
             << "8. Enlarge" << endl << "9. Shrink" << endl << "10. Mirror" << endl
             << "11. Shuffle" << endl << "12. Blur" << endl;
        cin >> choice;


    if (choice == 1){
        load_image();
        black_white_image();
        save_image();
    }
    
    if (choice == 2) {
        load_image();
        image_inverter();
        save_image_1();

    }
    if (choice == 3) {
            load_image();
            load_image_1();
            merge_filter();
            save_image_1();
        }

    if (choice == 4){
        cout << " 1.flip vertically" << endl << "2. flip horizontally" << endl;
        cin >> operation;

        if (operation == 1){
            load_image();
            flip_image_left_right();
            save_image();
        }

        if (operation == 2){
            load_image();
            flip_image_upside_down();
            save_image();
        }
    }
    
    if (choice == 5) {
            load_image();
            image_rotate();
            save_image_1();
        }
    if (choice == 6) {
            cout << "1.Lighten" << endl << "2.Darken" << endl;
            cin >> operation;

            if (operation == 1) {
                load_image();
                lighten();
                save_image_1();
            }


            if (operation == 2) {
                load_image();
                darken();
                save_image_1();
            }
        }
    if (choice == 9){
            int operation ;
            cout << " enter 1 ro 2 or 3";
            cin >> operation;
            if (operation == 1){
                load_image();
                shrink_image();
                save_image_1();
            }

            if (operation == 2 ){
                load_image();
                shrink_image_2();
                save_image_1();
            }

            if (operation == 3){
                load_image();
                shrink_image_3();
                save_image_1();
            }
        }

        if (choice == 10) {
            cout << " 1.Down" << endl << "2.Right" << endl << "3.Left" << endl << "4.Upper" << endl;
            cin >> operation;
            if (operation == 1) {
                load_image();
                mirror_1();
                save_image();
            }

            if (operation == 2) {
                load_image();
                mirror_2();
                save_image();
            }

            if (operation == 3) {
                load_image();
                mirror_3();
                save_image();
            }

            if (operation == 4) {
                load_image();
                mirror_4();
                save_image();
            }
        }




        if (operation == 12){
            load_image();
            blur_image();
            save_image();
        }

        cout << "if you want to continue press any button & if you want to exit press (N)";
        cin >> reuse;
        if ((reuse == 'n') || (reuse == 'N')){
            checker = false;
        }
    }
}



void load_image(){
    char image_file_name[100];

    cout << " Enter the source image file name :  " ;
    cin >> image_file_name;

    // add .bmp
    strcat(image_file_name,".bmp");
    readGSBMP(image_file_name,image);
}

void load_image_1(){
    char image_file_name[100];

    cout << " Enter the source image file name :  ";
    cin >> image_file_name;

    // addd .bmp
    strcat(image_file_name,".bmp");
    readGSBMP(image_file_name,new_image);
}

void save_image(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void save_image_1(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, new_image);
}

void black_white_image(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            if (image[i][j] > 128)
                image[i][j] = 255;
            else
                image[i][j] = 0;

        }

    }
}

void image_inverter() {
// filter 2
// invert the the gray and black pixel to its opposite white
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++)
            new_image[i][j]=255-image[i][j];
    }
}

void merge_filter(){
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 255; ++j) {

            new_image[i][j] = (image[i][j]+new_image[i][j]) / 2 ;

        }
    }
}

void flip_image_upside_down(){
    int temp ;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE/2; ++j) {
            temp = image[i][255-j];
            image[i][255-j]=image[i][j];
            image[i][j]=temp;
        }
    }
}

void flip_image_left_right(){
    int temp ;
    for (int i = 0; i < SIZE/2; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            temp = image[255-i][j];
            image[255-i][j]=image[i][j];
            image[i][j]=temp;
        }
    }
}

void image_rotate(){
// filter 5
// rotate the image by 90 or 180 or 270
    int rotate_number;
    // to choose the rotate number you want to do
    cout<< "Enter 90 for rotate 90 " << endl << "Enter 180 for rotate 180"
        << endl << "Enter 270 for rotate 270 " << endl;
    cin>>rotate_number;
    for(int i =0 ; i<SIZE;i++){
        for(int j =0;j<SIZE;j++){
            // rotate 270
            if(rotate_number==270)
                new_image[i][j]=image[j][SIZE-i];
                //rotate 90
            else if(rotate_number == 90)
                new_image[i][j]=image[SIZE-j][i];
                // rotate 180
            else if(rotate_number == 180)
                new_image[i][j]=image[SIZE-i][SIZE-j];
        }
    }
}

void lighten(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            unsigned char l = 0.5 * image[i][j];
            unsigned char ll = (127 + l);
            if (ll <= 0){
                ll = ll + 225 ;
            }
            new_image[i][j] = ll;
        }
    }
}


void darken(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = image[i][j] - 0.5*(image[i][j]);
            new_image[i][j] = image[i][j];
        }
    }
}

void moveQuarter( int i, int j )
{
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=2)
    {
        j = temp;
        for (int z=0; z< SIZE; j++ , z+=2){
            new_image[i][j]=image[k][z];
        }
    }
}

void moveQuarter_2( int i, int j )
{
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=3)
    {
        j = temp;
        for (int z=0; z< SIZE; j++ , z+=3){
            new_image[i][j]=image[k][z];
        }
    }
}

void moveQuarter_3( int i, int j )
{
    int temp = j;
    for (int k=0; k < SIZE; i++,k+=4)
    {
        j = temp;
        for (int z=0; z< SIZE; j++ , z+=4){
            new_image[i][j]=image[k][z];
        }
    }
}


void shrink_image(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter(0,0);
    }
}

void shrink_image_2(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter_2(0,0);
    }
}

void shrink_image_3(){
    for (int i =0 ; i <4 ; i++)
    {

        if (i==0) moveQuarter_3(0,0);
    }
}

void mirror_1(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j]=image[SIZE-(i)][(j)];

        }
    }
}


void mirror_2(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i][j]=image[(i)][256-(j)];

        }
    }
}

void mirror_3(){
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256/2; ++j) {
            image[i][j+128]=image[(i)][128-(j)];

        }
    }
}

void mirror_4(){
    for (int i = 0; i < 256/2; ++i) {
        for (int j = 0; j < 256; ++j) {
            image[i+128][j]=image[128-(i)][(j)];

        }
    }
}


void blur_image(){
    for(int i=0 ; i<SIZE ;i++)
        for(int j=0 ; j<SIZE ;j++)
            image[i][j] = ( image[i][j]+image[i+1][j+1]+image[i+1][j]+image[i][j+1]+image[i-1][j-1]+image[i-1][j]+image[i][j-1]
                            +image[i+4][j+4]+image[i+4][j]+image[i][j+4]+image[i-4][j-4]+image[i-4][j]+image[i][j-4]
                            +image[i+3][j+3]+image[i+3][j]+image[i][j+3]+image[i-3][j-3]+image[i-3][j]+image[i][j-3]
                            +image[i+2][j+2]+image[i+2][j]+image[i][j+2]+image[i-2][j-2]+image[i-2][j]+image[i][j-2] )/25 ;
}