/*
 * ------------------------------------------------
 * Declaracao de funcoes para implementacao simples 
 * de uma cifra de Cesar na linguagem C
 * 
 * UFSCar campus Sorocaba - Hackerspace - 2020
 * by: Infinitemarcus
 * ------------------------------------------------
 */

/*
 * Funcao que encripta a mensagem fornecida
 * utilizando o algoritmo da cifra de Cesar, uma dada frase 
 * e uma dada chave numerica
 * 
 * Cada caracter da frase eh percorrido em um loop,
 * ateh encontrar o final (\0). A criptografia eh feita
 * ao se adicionar ao caracter o valor da chave fornecida
 * 
 * Os caracteres que não são letras na tabela ASCII sao preservados
*/ 
void encripta(char * frase, int chave){

	char novaFrase[200];
	int i = 0;
	
	while(frase[i] != '\0'){
		
		novaFrase[i] = frase[i] + chave;
			
		if(frase[i] <= 122 && frase[i] >= 97){
			if((frase[i] + chave) > 122)
					novaFrase[i] -= 26;
				
			if((frase[i] + chave) < 97)
					novaFrase[i] += 26;
						
		}else if(frase[i] <= 90 && frase[i] >= 65){
			if((frase[i] + chave) > 90)
					novaFrase[i] -= 26;
				
			if((frase[i] + chave) < 65)
					novaFrase[i] += 26;
		}else
			novaFrase[i] -= chave;
                
        i++;
	}
	novaFrase[i] = '\0';
	
	strcpy(frase, novaFrase);
}

/*
 * Funcao que decripta a mensagem fornecida
 * utilizando o algoritmo da cifra de Cesar, uma dada frase
 * criptografada e uma dada chave numerica
 * 
 * Cada caracter da frase eh percorrido em um loop,
 * ateh encontrar o final (\0). A criptografia eh desfeita
 * ao se subtrair ao caracter o valor da chave fornecida
 * 
 * Os caracteres que não são letras na tabela ASCII sao preservados
*/ 
void decripta(char * frase, int chave){
	
	char novaFrase[200];
	int i = 0; 
	
	while(frase[i] != '\0'){
		
		novaFrase[i] = frase[i] - chave;
			
		if(frase[i] <= 122 && frase[i] >= 97){
			if((frase[i] - chave) > 122)
					novaFrase[i] -= 26;
				
			if((frase[i] - chave) < 97)
					novaFrase[i] += 26;
						
		}else if(frase[i] <= 90 && frase[i] >= 65){
			if((frase[i] - chave) > 90)
					novaFrase[i] -= 26;
				
			if((frase[i] - chave) < 65)
					novaFrase[i] += 26;
		}else
			novaFrase[i] += chave;
                
        i++;
	}
	novaFrase[i] = '\0';
	
	strcpy(frase, novaFrase);
}
