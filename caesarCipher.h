  /*
 * ------------------------------------------------------
 * Implementation of simple encript and decript functions
 * for Caesar Cipher in C language
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * ------------------------------------------------------
 */


/*
 * Encript function for Caesar Cipher, using ASCII letters
 * 
 * Non-ASCII chars are preserved
*/ 
void encript(char * message, int key){

	char newMessage[200];
	int i = 0;
	
	/*
	 * Looping every char from message, applying
	 * the key to get the encripted message 
	*/ 
	while(message[i] != '\0'){
		
		newMessage[i] = message[i] + key;
			
		//Verifying overflow in lowerCase chars 
		if(message[i] <= 122 && message[i] >= 97){
			if((message[i] + key) > 122)
					newMessage[i] -= 26;
				
			if((message[i] + key) < 97)
					newMessage[i] += 26;
						
		//Verifying overflow in upperCase chars 
		}else if(message[i] <= 90 && message[i] >= 65){
			if((message[i] + key) > 90)
					newMessage[i] -= 26;
				
			if((message[i] + key) < 65)
					newMessage[i] += 26;
					
		//Non-ASCII chars
		}else
			newMessage[i] -= key;
                
        i++;
	}
	newMessage[i] = '\0';
	
	//Overwriting original message
	strcpy(message, newMessage);
}

/*
 * Decript function for Caesar Cipher, using ASCII letters
 * 
 * Non-ASCII chars are preserved
*/ 
void decript(char * message, int key){
	
	char newMessage[200];
	int i = 0; 
	
	/*
	 * Looping every char from message, applying
	 * the key to get the original message 
	*/ 
	while(message[i] != '\0'){
		
		newMessage[i] = message[i] - key;
		
		//Verifying overflow in lowerCase chars 
		if(message[i] <= 122 && message[i] >= 97){
			if((message[i] - key) > 122)
					newMessage[i] -= 26;
				
			if((message[i] - key) < 97)
					newMessage[i] += 26;
					
		//Verifying overflow in upperCase chars 
		}else if(message[i] <= 90 && message[i] >= 65){
			if((message[i] - key) > 90)
					newMessage[i] -= 26;
				
			if((message[i] - key) < 65)
					newMessage[i] += 26;
					
		//Non-ASCII chars
		}else
			newMessage[i] += key;
                
        i++;
	}
	newMessage[i] = '\0';
	
	//Overwriting original message
	strcpy(message, newMessage);
}
