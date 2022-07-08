#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


    int main() {

        int typer;

        printf("Select the Menu\n1. Binary to Decimal\n2. Decimal to Binary\n3. Octal to Decimal\n4. Decimal to Octal\n5. Octal to Binary\n6. Binary to Octal\n7. Decimal to Hexadecimal\n8. Hexadecimal to Decimal\n9. Hexadecimal to Binary\n10. Binary to Hexadecimal\n->");
        scanf("%d", &typer);

        switch (typer) {

            case 1:
            {
                float binary;
                float cyc_dif= 0.0, decimal = 0.0, f_decimal = 0.0;
                int counter = 0, cyc = 0;
                int weight = 1;

                printf("Enter the Binary: ");
                scanf("%f", &binary);

                int int_part = (int)binary;
                float frac_part = binary - (float)int_part;

                while (int_part != 0) {
                    cyc = int_part % 10;
                    int cyc_dif = weight*cyc;
                    decimal += cyc_dif;
                    int_part = int_part/10;
                    weight = weight*2;

                }

                weight = 2.0;
                frac_part += 0.001;
                
                while ( counter < 2 ) {
                    counter++;
                    float sub = frac_part * 10;
                    cyc = (int)sub;
                    cyc_dif = 1.0 * cyc / weight;
                    f_decimal += cyc_dif;
                    int_part = int_part/10;
                    weight = weight*2;

                }

                decimal += f_decimal;

                printf("The decimal Value is %f", decimal);
                break;
            }

            case 2:
            {
                float input;
                int i, j, counter = 0;
                char a[100];

                printf("\nEnter the Decimal Number: ");
                scanf("%f", &input);

                int number = (int)input;
                float fract  = input - number + 0.0001;
                
                
                for(i = 0; number > 0; i++) {
                    a[i] = number % 2;
                    number = number / 2;
                }
                
                printf("\nThe Binary value is: ");
                for (j = i - 1;j >= 0; j--) {
                    counter++;
                    printf("%d", a[j] );
                }
                break;
            }

            case 3:
            {
                int octnum, decnum=0, i=0, rem;
                printf("Enter Octal Number:");
                scanf("%d", &octnum);
                while ( octnum != 0) 
                {
                    rem = octnum%10;
                    decnum = decnum + ( rem*pow(8,i));
                    i++;
                    octnum = octnum/10;
                }
                printf("\nDecimal Value = %d", decnum);

                break;    
            }
            
            
            case 4: 
            {
                unsigned int integer_part, fraction_part, len1, len2;
                double result;
                printf("Enter the Decimal: ");
                scanf("%o.%n%o%n", &integer_part, &len1, &fraction_part, &len2);
                result = fraction_part * 1.0 / (1<<(len2-len1)*3);
                result += integer_part;
                printf("Octal Number: %.6f\n",result);
                break;
            }


            case 5:
            {

                char octalnum[1000];
                long i = 0;
            
                printf("Enter any octal number: ");
                scanf("%s", octalnum);
                printf("Equivalent binary value: ");
                while (octalnum[i])
                {
                    switch (octalnum[i])
                    {
                    case '.':
                        printf("."); break;
                    case '0':
                        printf("000"); break;
                    case '1':
                        printf("001"); break;
                    case '2':
                        printf("010"); break;
                    case '3':
                        printf("011"); break;
                    case '4':
                        printf("100"); break;
                    case '5':
                        printf("101"); break;
                    case '6':
                        printf("110"); break;
                    case '7':
                        printf("111"); break;
                    
                    }
                    i++;
                }
                break;

            }


            case 6: 
            {

                int ic6, octal6 = 0, decimal6 = 0;
                long binary6;

                printf("Enter the Binary Number: ");
                scanf("%ld", &binary6);
                
                ic6 = 0;
                while(binary6 != 0)
                {
                    decimal6 = decimal6 + (binary6 % 10) * pow(2, ic6);
                    ic6++;
                    binary6 = binary6/10;
                }

                ic6 = 1;
                while(decimal6 != 0) 
                {
                    octal6 = octal6 + (decimal6 % 8) * ic6;
                    decimal6 = decimal6 / 8;
                    ic6 = ic6 * 10;
                }
                printf("The octal Value = %d\n", octal6);
                break;
            }
        
            case 7:
            {

                double input, ori, d_input; // input and some mod input
                double d, r, m, ex;
                char c;
                int ic7 = 0;
                char hex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx. 
                char fhex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx

                int len = sizeof(hex) / sizeof(char); //length of hex
                int len1 = sizeof(fhex) / sizeof(char); //length of fhex

                // ask for user input
                printf("Enter a decimal number: ");
                scanf(" %lf", &input);

                ori = input; // original input

                // convert from dec to hex for integer part
                while(d > 0 && input != 0){
                    ic7++;
                    d = (int)input / 16;
                    r = (int)input - ((int)d * 16);
                    input = (int)d;

                    if(r >= 10 && r <= 15){ //convert 10 to A ....... 15 to F
                        c = 'A' + (r - 10); // ASCII: 'A' = 65, if r = 12 then 'A' + (12 - 10) = 'A' + 2 = 67 = 'C'. why? 'cause in ASCII table 'C' correspond to 67
                        hex[len - ic7] = c; // add c to hex array
                    }
                    else{
                        hex[len - ic7] = (r + '0'); // r + '0' is to convert it into string
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
                    ic7 = 0;
                    d_input = ori - (int)ori; // to extract for decimal part from input

                    while(ex != 0){
                        m = d_input * 16;
                        ex = m - (int)m; // extract for decimal part after multiplication 
                        d_input = ex;
                        ic7++;

                        if((int)m >= 10 && (int)m <= 15){
                            c = 'A' + ((int)m - 10);
                            fhex[ic7] = c;
                        }
                        else{
                            fhex[ic7] = m + '0';
                        }  
                    }

                    // print hex result for decimal part
                    for(int i = 0; i <= len; i++){

                        if(fhex[i] != 'z') {
                            printf("%c", fhex[i]);
                            }
                        }
                    }
                break;
            }


            case 8: 
            {
                char hexa[100];
                float decimal = 0;
                int mul = 2;
                int* hex_len;
                int spliter;


                printf("Enter the Hexadecimal Numeber: ");
                scanf("%s", &hexa);

                int length = strlen(hexa);   

                for ( int i = 0; i < 5; i++ ) {

                    if ( hexa[i] == '.') {
                        spliter = 7;
                    }
                }

                if ( spliter != 7 ) {
                    length += 3;
                }

                if ( spliter == 7 ) {
                    for (int counter = 0; counter < 3; counter++ ) {
                        char letter = hexa[length - 1 - counter ];

                        if (letter >= '0' && letter <= '9') {
                            decimal += ( letter - '0' ) / pow(16, mul);
                            mul--;

                        }

                        else if ( letter == '.') {
                            decimal += 0;
                        }

                        else {
                            decimal += ( letter - 'A' + 10) / pow(16, mul);
                            mul --;
                        }

                    }  
                }

                mul = 0;

                for (int counter = 0; counter < length - 3; counter++) {

                    char letter = hexa[length - 1 - counter - 3];

                    if (letter >= '0' && letter <= '9') {
                        decimal += ( letter - '0' ) * pow(16, mul);
                        mul++;

                    }

                    else {
                        decimal += ( letter - 'A' + 10) * pow(16, mul);
                        mul ++;
                    }
                }

                printf("The decimal number is %f", decimal);
                break;

            }


            case 9:
            {

                printf("Hexadecimal to Binary");

                char hexadecimal[100];

                printf("\nEnter the Hexadecimal: ");
                scanf("%s", &hexadecimal);

                int length = strlen(hexadecimal);
                printf("%d", length);

                printf("\nThe Binary Number: "); 

                for ( int count = 0; count < length; count++) {

                    switch (hexadecimal[count]){

                        case '.' :  printf(".");
                                    break;
                        case '0' :  printf("0000");
                                    break;
                        case '1' :  printf("0001");
                                    break;
                        case '2' :  printf("0010");
                                    break;
                        case '3' :  printf("0011");
                                    break;
                        case '4' :  printf("0100");
                                    break;
                        case '5' :  printf("0101");
                                    break;
                        case '6' :  printf("0110");
                                    break;
                        case '7' :  printf("0111");
                                    break;
                        case '8' :  printf("1000");
                                    break;
                        case '9' :  printf("1001");
                                    break;
                        case 'A' :  printf("1010");
                                    break;
                        case 'B' :  printf("1011");
                                    break;
                        case 'C' :  printf("1100");
                                    break;
                        case 'D' :  printf("1101");
                                    break;
                        case 'E' :  printf("1110");
                                    break;
                        case 'F' :  printf("1111");
                                    break;
                        case 'a' :  printf("1010");
                                    break;
                        case 'b' :  printf("1011");
                                    break;
                        case 'c' :  printf("1100");
                                    break;
                        case 'd' :  printf("1101");
                                    break;
                        case 'e' :  printf("1110");
                                    break;
                        case 'f' :  printf("1111");
                                    break;
                        

                    }
                    
                    

                }
                break;
            }

            
            case 10:
            {
                float binary;
                float cyc_dif= 0.0, decimal = 0.0, f_decimal = 0.0;
                int counter = 0, cyc = 0;
                int weight = 1;

                printf("Enter the Binary: ");
                scanf("%f", &binary);

                int int_part = (int)binary;
                float frac_part = binary - (float)int_part;

                while (int_part != 0) {
                    cyc = int_part % 10;
                    int cyc_dif = weight*cyc;
                    decimal += cyc_dif;
                    int_part = int_part/10;
                    weight = weight*2;

                }

                weight = 2.0;
                frac_part += 0.001;
                
                while ( counter < 2 ) {
                    counter++;
                    float sub = frac_part * 10;
                    cyc = (int)sub;
                    cyc_dif = 1.0 * cyc / weight;
                    f_decimal += cyc_dif;
                    int_part = int_part/10;
                    weight = weight*2;

                }

                decimal += f_decimal;

                float input, ori, d_input; // input and some mod input
                float d, r, m, ex;
                char c;
                int ic7 = 0;
                char hex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for integer part xxxx. 
                char fhex[] = "zzzzzzzzzzzzzzzzzzz"; // add random elements for decimal part .xxxxx

                int len = sizeof(hex) / sizeof(char); //length of hex
                int len1 = sizeof(fhex) / sizeof(char); //length of fhex

                // ask for user input
                input = decimal;
                ori = input; // original input

                // convert from dec to hex for integer part
                while(d > 0 && input != 0){
                    ic7++;
                    d = (int)input / 16;
                    r = (int)input - ((int)d * 16);
                    input = (int)d;

                    if(r >= 10 && r <= 15){ //convert 10 to A ....... 15 to F
                        c = 'A' + (r - 10); // ASCII: 'A' = 65, if r = 12 then 'A' + (12 - 10) = 'A' + 2 = 67 = 'C'. why? 'cause in ASCII table 'C' correspond to 67
                        hex[len - ic7] = c; // add c to hex array
                    }
                    else{
                        hex[len - ic7] = (r + '0'); // r + '0' is to convert it into string
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
                    ic7 = 0;
                    d_input = ori - (int)ori; // to extract for decimal part from input

                    while (ex != 0) {
                        m = d_input * 16;
                        ex = m - (int)m; // extract for decimal part after multiplication 
                        d_input = ex;
                        ic7++;

                        if((int)m >= 10 && (int)m <= 15){
                            c = 'A' + ((int)m - 10);
                            fhex[ic7] = c;
                        }
                        else{
                            fhex[ic7] = m + '0';
                        }  
                    }

                    // print hex result for decimal part
                    for(int i = 0; i <= len; i++){

                        if(fhex[i] != 'z') {
                            printf("%c", fhex[i]);

                            }
                        }
                    }
            }
            
            case 11:
            {
                printf("Exit");
                // long binaryval; 
                // int hexadecimalval = 0, i = 1, remainder;
 
                // printf("Enter the binary number: ");
                // scanf("%ld", &binaryval);
                // while (binaryval != 0)
                // {
                //     remainder = binaryval % 10;
                //     hexadecimalval = hexadecimalval + remainder * i;
                //     i = i * 2;
                //     binaryval = binaryval / 10;
                // }
                // printf("Equivalent hexadecimal value: %lX", hexadecimalval);
                // break;
            }


        }


    }
