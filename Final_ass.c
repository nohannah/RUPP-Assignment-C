#include<stdio.h>
#include<math.h>
#include <string.h>

int main(){
    int op;
    //long binary,decimal,octal ,hexaDecimal;


    /*
    Output there are 10 convert functions
    Show it and input under this output
    */
    printf("\t=========== MENU ===========\n");
    printf("\t 1.Convert Binary to Decimal\n");
    printf("\t 2.Convert Decimal to Binary\n");
    printf("\t 3.Convert Octal to Decimal\n");
    printf("\t 4.Convert Decimal to Octal\n");
    printf("\t 5.Convert Octal to Binary\n");
    printf("\t 6.Convert Binary to Octal\n");
    printf("\t 7.Convert Decimal to Hexadecimal\n");
    printf("\t 8.Convert Hexadecimal to Decimal\n");
    printf("\t 9.Convert Hexadecimal to Binary\n");
    printf("\t10.Convert Binary to Hexadecimal\n");
    printf("\t------------------------------------\n");

    //Function to choose which you want to convert
    printf("\tChoose One :"); scanf("%d",&op);
    switch(op)
    {
        {
        case 1:  ;//convert binary to decimal
            char bi[] = "zzzzzzzzzzzzzzzzzzz"; //for user input
            char i_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for integer part
            char d_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for decimal part
            char hex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char fhex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx
            double n, sum;
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int s = 0, x = 0, j = 0, i = 0, k = 0, p;
            int len = sizeof(bi) / sizeof(char);
            int len_i = sizeof(i_part) / sizeof(char);
            int len_d = sizeof(d_part) / sizeof(char);
            int len_hex = sizeof(hex) / sizeof(char); //length of hex
            int len1 = sizeof(fhex) / sizeof(char); //length of fhex

            //input from user
            printf("Enter binary number: ");
            getchar();
            gets(bi);

            for(int i = 0; i < len; i++){
                if(bi[i] != 'z' && bi[i] != 0){ //0 is correspond to NUL in ASCII
                    if(bi[i] != '.'){
                        s++; //for counting the num in integer part
                    }

                    j++; //iteration for int part

                    //adding elements starting from '.' to d_part[] array. ex: 123.aDb => .aDb
                    if(bi[i] == '.'){
                        for(; i < len; i++){
                            if(bi[i] != 'z' && bi[i] != 0 && bi[i] != '.'){ //0 is correspond to NUL in ASCII
                                d_part[k] = bi[i];
                            }

                            k++;
                        }
                        break;
                    }

                    // adding elements before '.'. ex: 123.aDb => 123
                    i_part[j] = bi[i];
                }
            }

            //calculate integer part
            for(j = 0; j <= len_i; j++){
                x = (s) - j; // access element from the back of the array

                if(i_part[j] != 'z' && i_part[j] != 0){ //0 is correspond to NUL in ASCII
                    if(i_part[j] >= '0' && i_part[j] <= '1'){
                        n = (i_part[j] - 48) * (pow(2, x));
                        sum += n;
                        p = 1;
                    }
                }
            }

            // calculate the decimal part
            for(k= 1; k <= len_d; k++){
                x = (-k);

                if(d_part[k] != 'z' && d_part[k] != 0){

                    if(d_part[k] >= '0' && d_part[k] <= '1'){
                        n = (d_part[k] - 48) * (pow(2, x));
                        sum += n;
                        p = 2;
                    }
                }
            }

            // display result
            if(p == 1){ //for output in integer format
                printf("%g", sum);
            }
            else if(p == 2){ //for output in long float format
                printf("%lf", sum);
            }




        break;//ready
        }

        {
        case 2:  ;//convert decimal to binary
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int i = 0;
            char bi[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char fbi[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx

            int len = sizeof(bi) / sizeof(char); //length of bi
            int len1 = sizeof(fbi) / sizeof(char); //length of fbi

            // ask for user input
            printf("Enter a decimal number: ");
            scanf(" %lf", &input);

            ori = input; // original input

            // convert from dec to bi for integer part
            while(d > 0 && input != 0){
                i++;
                d = (int)input / 2;
                r = (int)input - ((int)d * 2);
                input = (int)d;

                bi[len - i] = (r + '0'); // r + '0' is to convert it into string
            }

            // print bi result for integer part
            for(int i = 0; i <= len; i++){
                if(bi[i] != 'z'){
                printf("%c", bi[i]);
                }
                }

            // covert from dec to bi for decimal part
            if(ori > (int)ori){
                printf(".");
                i = 0;
                d_input = ori - (int)ori; // to extract for decimal part from input

                while(ex != 0){
                    m = d_input * 2;
                    ex = m - (int)m; // extract for decimal part after multiplication
                    d_input = ex;
                    i++;

                    fbi[i] = m + '0';

                }

                // print bi result for decimal part
                for(int i = 0; i <= len; i++){
                if(fbi[i] != 'z'){
                printf("%c", fbi[i]);
                }
                }
            }
        /*
            long double f, binaryTotal, binaryFrac = 0.0, frac, fracFractor = 0.1;
            long int integer, binaryInt = 0;
            long int p = 0, rem, temp;

            printf("\nEnter floating number: ");
            scanf("%Lf", &f);

            //separate the integer part from the input floating number
            integer = (int)f;

            //separate the fractional part from the input floating number
            frac = f - integer;

            //loop to convert integer part to binary
            while (integer != 0) {
                rem = integer % 2;
                binaryInt = binaryInt + rem *pow(10, p);
                integer = integer / 2;
                p++;
            }

            //loop to convert fractional part to binary
            while (frac != 0) {
                frac = frac * 2;
                temp = frac;
                binaryFrac = binaryFrac + fracFractor * temp;
                if (temp == 1)
                    frac = frac - temp;

                fracFractor = fracFractor / 10;
            }

            binaryTotal = binaryInt + binaryFrac;
            printf("binary equivalent = %Lf\n", binaryTotal);
        */
        break;

        }

        {
        case 3:  ;//convert octal to decimal
            char dec[] = "zzzzzzzzzzzzzzzzzzz"; //for user input
            char i_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for integer part
            char d_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for decimal part
            double n, sum;
            int len = sizeof(dec) / sizeof(char);
            int len_i = sizeof(i_part) / sizeof(char);
            int len_d = sizeof(d_part) / sizeof(char);
            int s = 0, x = 0, j = 0, i = 0, k = 0, p;

            //input from user
            printf("Enter octal number: ");
            getchar();
            gets(dec);
              printf("\nThe Decimal Number of Octal Number above is : ");

            for(int i = 0; i < len; i++){
                if(dec[i] != 'z' && dec[i] != 0){ //0 is correspond to NUL in ASCII
                    if(dec[i] != '.'){
                        s++; //for counting the num in integer part
                    }

                    j++; //iteration for int part

                    //adding elements starting from '.' to d_part[] array. ex: 123.aDb => .aDb
                    if(dec[i] == '.'){
                        for(; i < len; i++){
                            if(dec[i] != 'z' && dec[i] != 0){ //0 is correspond to NUL in ASCII
                                d_part[k] = dec[i];
                            }
                            k++;
                        }
                        break;
                    }

                    // adding elements before '.'. ex: 123.aDb => 123
                    i_part[j] = dec[i];
                }
            }

            //calculate integer part
            for(j = 0; j <= len_i; j++){
                x = (s) - j; // access element from the back of the array

                if(i_part[j] != 'z' && i_part[j] != 0){ //0 is correspond to NUL in ASCII
                    if(i_part[j] >= '0' && i_part[j] <= '9'){
                        n = (i_part[j] - 48) * (pow(8, x));
                        sum += n;
                        p = 1;
                    }
                    else{
                        p = 3; //for printing
                        break;
                    }
                }
            }

            // calculate the decimal part
            for(k= 1; k <= len_d; k++){
                x = (-k);

                if(p == 3){ //if the integer input is incorrect
                    break;
                }

                if(d_part[k] != 'z' && d_part[k] != 0){

                    if(d_part[k] >= '0' && d_part[k] <= '9'){
                        n = (d_part[k] - 48) * (pow(8, x));
                        sum += n;
                        p = 2;
                    }
                    else{
                        p = 3;
                        break;
                    }
                }
            }

            // display result
            if(p == 1){ //for output in integer format
                printf("%g", sum);
            }
            else if(p == 2){ //for output in long float format
                printf("%lf", sum);
            }
            else if(p == 3){ // if the input is incorrect
                printf("Try again.");
            }
        break;//ready
        }

        {
        case 4: ;//convert decimal to octal
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int i = 0;
            char oct[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char foct[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx

            int len = sizeof(oct) / sizeof(char); //length of oct
            int len1 = sizeof(foct) / sizeof(char); //length of foct

            // ask for user input
            printf("Enter a decimal number: ");
            scanf(" %lf", &input);
            printf("\nThe Octal Number of Decimal Number above is : ");

            ori = input; // original input

            // convert from dec to oct for integer part
            while(d > 0 && input != 0){
                i++;
                d = (int)input / 8;
                r = (int)input - ((int)d * 8);
                input = (int)d;

                oct[len - i] = (r + '0'); // r + '0' is to convert it into string
            }

            // print oct result for integer part
            for(int i = 0; i <= len; i++){
                if(oct[i] != 'z'){
                printf("%c", oct[i]);
                }
                }

            // covert from dec to oct for decimal part
            if(ori > (int)ori){
                printf(".");
                i = 0;
                d_input = ori - (int)ori; // to extract for decimal part from input

                while(ex != 0){
                    m = d_input * 8;
                    ex = m - (int)m; // extract for decimal part after multiplication
                    d_input = ex;
                    i++;

                    foct[i] = m + '0';

                }

                // print oct result for decimal part
                for(int i = 0; i <= len; i++){
                if(foct[i] != 'z'){
                printf("%c", foct[i]);
                }
                }
            }

        break;
        }

        {
        case 5:  ;//convert octal to decimal
            char octNum[100];
            int len;

            printf("Enter Octal Number : ");
            getchar();
            gets(octNum);
            printf("\nThe Decimal Number of Octal Number above is : ");
            len = strlen(octNum);
            for(int count = 0; count < len; count++){
                // printf("\n--%c--\n", octNum[count]);
                if ( octNum[count] == '0' ){
                        printf("000");
                    }
                else if ( octNum[count] == '1' ){
                    printf("001");
                    }
                else if ( octNum[count] == '2' ){
                    printf("010");
                    }
                else if ( octNum[count] == '3' ){
                    printf("011");
                    }
                else if ( octNum[count] == '4' ){
                    printf("100");
                    }
                else if ( octNum[count] == '5' ){
                    printf("101");
                    }
                else if ( octNum[count] == '6' ){
                    printf("110");
                    }
                else if ( octNum[count] == '7' ){
                    printf("111");
                    }
                else if ( octNum[count] == '.'){
                    printf(".");
                    }
            }
        break;//ready
        }

        {
        case 6:  ;//convert decimal to octal
            char bi[] = "zzzzzzzzzzzzzzzzzzz"; //for user input
            char i_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for integer part
            char d_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for decimal part
            char oct[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char foct[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx
            double n, sum;
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int s = 0, x = 0, j = 0, i = 0, k = 0, p;
            int len = sizeof(bi) / sizeof(char);
            int len_i = sizeof(i_part) / sizeof(char);
            int len_d = sizeof(d_part) / sizeof(char);
            int len_oct = sizeof(oct) / sizeof(char); //length of oct
            int len1 = sizeof(foct) / sizeof(char); //length of foct

            //input from user3
            printf("Enter binary number: ");
            getchar();
            gets(bi);
            printf("\nThe Octal Number of Decimal Number above is : ");


            for(int i = 0; i < len; i++){
                if(bi[i] != 'z' && bi[i] != 0){ //0 is correspond to NUL in ASCII
                    if(bi[i] != '.'){
                        s++; //for counting the num in integer part
                    }

                    j++; //iteration for int part

                    //adding elements starting from '.' to d_part[] array. ex: 123.aDb => .aDb
                    if(bi[i] == '.'){
                        for(; i < len; i++){
                            if(bi[i] != 'z' && bi[i] != 0 && bi[i] != '.'){ //0 is correspond to NUL in ASCII
                                d_part[k] = bi[i];
                            }

                            k++;
                        }
                        break;
                    }

                    // adding elements before '.'. ex: 123.aDb => 123
                    i_part[j] = bi[i];
                }
            }

            //calculate integer part
            for(j = 0; j <= len_i; j++){
                x = (s) - j; // access element from the back of the array

                if(i_part[j] != 'z' && i_part[j] != 0){ //0 is correspond to NUL in ASCII
                    if(i_part[j] >= '0' && i_part[j] <= '1'){
                        n = (i_part[j] - 48) * (pow(2, x));
                        sum += n;
                        p = 1;
                    }
                }
            }

            // calculate the decimal part
            for(k= 1; k <= len_d; k++){
                x = (-k);

                if(d_part[k] != 'z' && d_part[k] != 0){

                    if(d_part[k] >= '0' && d_part[k] <= '1'){
                        n = (d_part[k] - 48) * (pow(2, x));
                        sum += n;
                        p = 2;
                    }
                }
            }

            if(p == 1){
            input = (long int)sum;
            }
            else if(p == 2){
            input = sum;
            }

            ori = input; // original input

            i = 0; //restart iteration

            // convert from dec to oct for integer part
            while(d > 0 && input != 0){
                i++;
                d = (int)input / 8;
                r = (int)input - ((int)d * 8);
                input = (int)d;
                oct[len_oct - i] = (r + '0'); // r + '0' is to convert it into string
            }

            // print oct result for integer part
            for(int i = 0; i <= len_oct; i++){
                if(oct[i] != 'z'){
                printf("%c", oct[i]);
                }
            }

            // covert from dec to oct for decimal part
            if(ori > (int)ori){
                printf(".");
                i = 0;
                d_input = ori - (int)ori; // to extract for decimal part from input

                while(ex != 0){
                    m = d_input * 8;
                    ex = m - (int)m; // extract for decimal part after multiplication
                    d_input = ex;
                    i++;
                    foct[i] = m + '0';
                }

                // print oct result for decimal part
                for(int i = 0; i <= len_oct; i++){
                if(foct[i] != 'z'){
                printf("%c", foct[i]);
                }
            }
            }
        break;//ready
        }

        {
        case 7:  ;//convert decimal to hexadecimal
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int i = 0;
            char hex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char fhex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx

            int len = sizeof(hex) / sizeof(char); //length of hex
            int len1 = sizeof(fhex) / sizeof(char); //length of fhex

            // ask for user input
            printf("Enter a decimal number: ");
            scanf(" %lf", &input);
             printf("\nThe Hexadecimal Number of Decimal Number above is : ");

            ori = input; // original input

            // convert from dec to hex for integer part
            while(d > 0 && input != 0){
                i++;
                d = (int)input / 16;
                r = (int)input - ((int)d * 16);
                input = (int)d;

                if(r >= 10 && r <= 15){ //convert 10 to A ....... 15 to F
                    c = 'A' + (r - 10); // ASCII: 'A' = 65, if r = 12 then 'A' + (12 - 10) = 'A' + 2 = 67 = 'C'. why? 'cause in ASCII table 'C' correspond to 67
                    hex[len - i] = c; // add c to hex array
                }
                else{
                    hex[len - i] = (r + '0'); // r + '0' is to convert it into string
                }
            }

            // print hex result for integer part
            for(int i = 0; i <= len; i++){
                if(hex[i] != 'z'){
                printf("%c", hex[i]);
                }
                }

            // covert from dec to hex for decimal part
            if(ori > (int)ori){
                printf(".");
                i = 0;
                d_input = ori - (int)ori; // to extract for decimal part from input

                while(ex != 0){
                    m = d_input * 16;
                    ex = m - (int)m; // extract for decimal part after multiplication
                    d_input = ex;
                    i++;

                    if((int)m >= 10 && (int)m <= 15){
                        c = 'A' + ((int)m - 10);
                        fhex[i] = c;
                    }
                    else{
                        fhex[i] = m + '0';
                    }
                }

                // print hex result for decimal part
                for(int i = 0; i <= len; i++){
                if(fhex[i] != 'z'){
                printf("%c", fhex[i]);
                }
                }
            }
        break;//ready
        }

        {
        case 8: ;//convert Hexadecimal to Decimal
            double input;
            char dec[] = "zzzzzzzzzzzzzzzzzzz"; //for user input
            char i_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for integer part
            char d_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for decimal part
            double n, sum;
            int len = sizeof(dec) / sizeof(char);
            int len_i = sizeof(i_part) / sizeof(char);
            int len_d = sizeof(d_part) / sizeof(char);
            int s = 0, x = 0, j = 0, i = 0, k = 0, p;

            //input from user
            printf("Enter hexadecimal number: ");
            getchar();
            gets(dec);
             printf("\nThe Decimal Number of Hexadecimal Number above is : ");

            for(int i = 0; i < len; i++){
                if(dec[i] != 'z' && dec[i] != 0){ //0 is correspond to NUL in ASCII
                    if(dec[i] != '.'){
                        s++; //for counting the num in integer part
                    }

                    j++; //iteration for int part

                    //adding elements starting from '.' to d_part[] array. ex: 123.aDb => .aDb
                    if(dec[i] == '.'){
                        for(; i < len; i++){
                            if(dec[i] != 'z' && dec[i] != 0){
                                d_part[k] = dec[i];
                            }
                            k++;
                        }
                        break;
                    }
                    // adding elements before '.'. ex: 123.aDb => 123
                    i_part[j] = dec[i];
                }
            }

            //calculate integer part
            for(j = 0; j <= len_i; j++){
                x = (s) - j;

                if(i_part[j] != 'z' && i_part[j] != 0){ //0 is correspond to NUL in ASCII

                    if(i_part[j] >= 'A' && i_part[j] <= 'F'){
                        n = (i_part[j] - 55) * (pow(16, x));
                        sum += n; //sum up the result
                        p = 1; //for printing
                    }
                    else if(i_part[j] >= 'a' && i_part[j] <= 'f'){
                        n = (i_part[j] - 87) * (pow(16, x));
                        sum += n;
                        p = 1;
                    }
                    else if(i_part[j] >= '0' && i_part[j] <= '9'){
                        n = (i_part[j] - 48) * (pow(16, x));
                        sum += n;
                        p = 1;
                    }
                    else{
                        p = 3; //for printing
                        break;
                    }
                }
            }

            // calculate the decimal part
            for(k= 1; k <= len_d; k++){
                x = (-k);

                if(p == 3){ //if the integer input is incorrect
                    break;
                }

                if(d_part[k] != 'z' && d_part[k] != 0){

                    if(d_part[k] >= 'A' && d_part[k] <= 'F'){
                        n = (d_part[k] - 55) * (pow(16, x));
                        sum += n;
                            p = 2; //for printing
                    }
                    else if(d_part[k] >= 'a' && d_part[k] <= 'f'){
                        n = (d_part[k] - 87) * (pow(16, x));
                        sum += n;
                        p = 2;
                    }
                    else if(d_part[k] >= '0' && d_part[k] <= '9'){
                        n = (d_part[k] - 48) * (pow(16, x));
                        sum += n;
                        p = 2;
                    }
                    else{
                        p = 3;
                        break;
                    }
                }
            }

            // display result
            if(p == 1){ //for output in integer format
                printf("%g", sum);
            }
            else if(p == 2){ //for output in long float format
                printf("%lf", sum);
            }
            else if(p == 3){ // if the input is incorrect
                printf("Try again.");
            }
        break;//ready
        }

        {
        case 9:  ;//convert Hexadecimal to Binary
            char hexNum[100]; //store 100 values
            long int count=0; //use to store small and large interger
            printf("Enter a hexadecimal number To Convet it into Binary : ");
            scanf("%s",hexNum); //ask for user input
            printf("\nBinary Number is : ");
            while(hexNum[count]) //count variable
            {
                switch(hexNum[count]) // check the value to output
                {
                    case '0' : printf("0000");
                        break;
                    case '1' : printf("0001");
                        break;
                    case '2' : printf("0010");
                        break;
                    case '3' : printf("0011");
                        break;
                    case '4' : printf("0100");
                        break;
                    case '5' : printf("0101");
                        break;
                    case '6' : printf("0110");
                        break;
                    case '7' : printf("0111");
                        break;
                    case '8' : printf("1000");
                        break;
                    case '9' : printf("1001");
                        break;
                    case 'A' : printf("1010");
                        break;
                    case 'B' : printf("1011");
                        break;
                    case 'C' : printf("1100");
                        break;
                    case 'D' : printf("1101");
                        break;
                    case 'E' : printf("1110");
                        break;
                    case 'F' : printf("1111");
                        break;
                    case 'a' : printf("1010");
                        break;
                    case 'b' : printf("1011");
                        break;
                    case 'c' : printf("1100");
                        break;
                    case 'd' : printf("1101");
                        break;
                    case 'e' : printf("1110");
                        break;
                    case 'f' : printf("1111");
                        break;
                    default : printf("\nInvalid Entry, Please Try Again  %c",hexNum[count]); //different from the case above print this
                }
                count++; //loop
            }
        break;//ready
        }

        {
        case 10:  ;//convert Binary to Hexadecimal
            char bi[] = "zzzzzzzzzzzzzzzzzzz"; //for user input
            char i_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for integer part
            char d_part[] = "zzzzzzzzzzzzzzzzzzzzz"; //for decimal part
            char hex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx.
            char fhex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx
            double n, sum;
            double input, ori, d_input; // input and some mod input
            double d, r, m, ex;
            char c;
            int s = 0, x = 0, j = 0, i = 0, k = 0, p;
            int len = sizeof(bi) / sizeof(char);
            int len_i = sizeof(i_part) / sizeof(char);
            int len_d = sizeof(d_part) / sizeof(char);
            int len_hex = sizeof(hex) / sizeof(char); //length of hex
            int len1 = sizeof(fhex) / sizeof(char); //length of fhex

            //input from user
            printf("Enter binary number: ");
            getchar();
            gets(bi);

            for(int i = 0; i < len; i++){
                if(bi[i] != 'z' && bi[i] != 0){ //0 is correspond to NUL in ASCII
                    if(bi[i] != '.'){
                        s++; //for counting the num in integer part
                    }

                    j++; //iteration for int part

                    //adding elements starting from '.' to d_part[] array. ex: 123.aDb => .aDb
                    if(bi[i] == '.'){
                        for(; i < len; i++){
                            if(bi[i] != 'z' && bi[i] != 0 && bi[i] != '.'){ //0 is correspond to NUL in ASCII
                                d_part[k] = bi[i];
                            }

                            k++;
                        }
                        break;
                    }

                    // adding elements before '.'. ex: 123.aDb => 123
                    i_part[j] = bi[i];
                }
            }

            //calculate integer part
            for(j = 0; j <= len_i; j++){
                x = (s) - j; // access element from the back of the array

                if(i_part[j] != 'z' && i_part[j] != 0){ //0 is correspond to NUL in ASCII
                    if(i_part[j] >= '0' && i_part[j] <= '1'){
                        n = (i_part[j] - 48) * (pow(2, x));
                        sum += n;
                        p = 1;
                    }
                }
            }

            // calculate the decimal part
            for(k= 1; k <= len_d; k++){
                x = (-k);

                if(d_part[k] != 'z' && d_part[k] != 0){

                    if(d_part[k] >= '0' && d_part[k] <= '1'){
                        n = (d_part[k] - 48) * (pow(2, x));
                        sum += n;
                        p = 2;
                    }
                }
            }

            if(p == 1){
            input = (long int)sum;
            }
            else if(p == 2){
            input = sum;
            }

            ori = input; // original input

            i = 0; //restart iteration

            // convert from dec to hex for integer part
            while(d > 0 && input != 0){
                i++;
                d = (int)input / 16;
                r = (int)input - ((int)d * 16);
                input = (int)d;

                if(r >= 10 && r <= 15){ //convert 10 to A ....... 15 to F
                    c = 'A' + (r - 10); // ASCII: 'A' = 65, if r = 12 then 'A' + (12 - 10) = 'A' + 2 = 67 = 'C'. why? 'cause in ASCII table 'C' correspond to 67
                    hex[len_hex - i] = c; // add c to hex array
                }
                else{
                    hex[len_hex - i] = (r + '0'); // r + '0' is to convert it into string
                }
            }

            // print hex result for integer part
            for(int i = 0; i <= len_hex; i++){
                if(hex[i] != 'z'){
                printf("%c", hex[i]);
                }
            }

            // covert from dec to hex for decimal part
            if(ori > (int)ori){
                printf(".");
                i = 0;
                d_input = ori - (int)ori; // to extract for decimal part from input

                while(ex != 0){
                    m = d_input * 16;
                    ex = m - (int)m; // extract for decimal part after multiplication
                    d_input = ex;
                    i++;

                    if((int)m >= 10 && (int)m <= 15){
                        c = 'A' + ((int)m - 10);
                        fhex[i] = c;
                    }
                    else{
                        fhex[i] = m + '0';
                    }
                }

                // print hex result for decimal part
                for(int i = 0; i <= len_hex; i++){
                if(fhex[i] != 'z'){
                printf("%c", fhex[i]);
                }
            }
            }
        break;//ready
        }
    }

    return 0;
}
