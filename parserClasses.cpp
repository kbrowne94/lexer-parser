//Use only the following libraries:
#include "parserClasses.h"
#include <string>
#include <iostream>

//Complete the implementation of the following member functions:

//****TokenList class function definitions******

//Creates a new token for the string input, str
//Appends this new token to the TokenList
//On return from the function, it will be the last token in the list
void TokenList::append(const string &str) { 
	Token* token = new Token;
	token -> setStringRep(str); 
	append(token);
}

//Appends the token to the TokenList if not null
//On return from the function, it will be the last token in the list
void TokenList::append(Token *token) { 
	
	if (tail == NULL && head==NULL)
	{
		token -> next = NULL;
		token -> prev = NULL;
		head = token;
		tail = token;

	}
	else
	{
		tail -> next = token;
		token -> prev = tail;
		token -> next = NULL;
		tail = token;
	}

return;
}

//Removes the token from the linked list if it is not null
//Deletes the token
//On return from function, head, tail and the prev and next Tokens (in relation to the provided token) may be modified.
void TokenList::deleteToken(Token *token) { 
	Token* temp;
	temp = new Token;
	temp->stringRep= token->stringRep;
	
	if(head==NULL|| temp ==NULL)
	{
		return;
	}
	
	if( head == temp){
		head= temp->next; 
	}
	if(temp->next !=NULL)
	{
		temp ->next->prev=temp->prev;
	}
	if(temp->prev !=NULL)
	{
		temp->prev->next= temp->next;
	}
	delete temp;
return;
}


//****Tokenizer class function definitions******

//Computes a new tokenLength for the next token
//Modifies: size_t tokenLength, and bool complete
//(Optionally): may modify offset
//Does NOT modify any other member variable of Tokenizer
void Tokenizer::prepareNextToken(){
	//this totally works, trust me
	//BUUTTTTTTT do NOT put in characters like a-z and A-Z
	//BUT WAIT, THEREs MORE!
	//you can include numbers but make sure that its not that last character in the string
	
	if (offset==str->length())
	{
		complete = true;
		return;
	}


	while (!isComplete())
	{
		if (offset == str->length())
		{
			return;
		} 
		
		if ((str->at(offset)==' ') || (str->at(offset)=='\t'))
		{
				offset = offset + 1;
				if (offset==str->length())
				{
					return;
					
				}
				return;
		}
			else if (str->at(offset)=='+')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}

				}
				else if (str->at(offset)=='+')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}
			else if (str->at(offset)=='-')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
					return;
				}
				else if (str->at(offset)=='-')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if (str->at(offset)=='>')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}
		
			else if (str->at(offset)=='*')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='/')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				/*else if (str->at(offset)=='/')
				{
					//this is for the line comment
				}*/
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='%')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='.')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='*')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)==',')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)==':')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)==':')
				{
					tokenLength++;
					offset++;
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='?')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)==':')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='=')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='!')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='<')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if (str->at(offset)=='<')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
					if (str->at(offset)=='=')
					{
						tokenLength++;
						offset++;
						
						return;
					}
					return;
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='>')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if (str->at(offset)=='>')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
					if (str->at(offset)=='=')
					{
						tokenLength++;
						offset++;
						
						return;
					}
					return;
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='&')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='&')
				{
					tokenLength++;
					offset++;
					
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='|')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='|')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				else if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='~')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='^')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}
				if (str->at(offset)=='=')
				{
					tokenLength++;
					offset++;
					if (offset == str->length())
					{
						return;
					}
					if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
					{
						return;
					}
					
				}
				
				else if ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					return;
				}
				
				return;
			}

			else if (str->at(offset)=='{')
			{
				tokenLength++;
				offset++;
				return;
			}
			
			else if (str->at(offset)=='}')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='(')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)==')')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='[')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)==']')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='<')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='>')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)==';')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='\'')
			{
				tokenLength++;
				offset++;
				return;
			}

			else if (str->at(offset)=='\"')
			{
				tokenLength++;
				offset++;
				return;
			}

			else
			{
				while ((str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_'))
				{
					tokenLength++;
					offset++;
				}
				return;

			}

			//this is me trying to get the characters working
			//the characters work when they are not in the last position of the string
			/*if (str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_')
			{
				tokenLength++;
				offset++;
				if (offset == str->length())
					{
						return;
					}

			} while (str->at(offset) == 'a'||str->at(offset) == 'b'||str->at(offset) == 'c'||str->at(offset) == 'd'||str->at(offset) == 'e'||str->at(offset) == 'f'
           ||str->at(offset) == 'g'||str->at(offset) == 'h'||str->at(offset) == 'i'||str->at(offset) == 'j'||str->at(offset) == 'k'||str->at(offset) == 'l'
           ||str->at(offset) == 'm'||str->at(offset) == 'n'||str->at(offset) == 'o'||str->at(offset) == 'p'||str->at(offset) == 'q'||str->at(offset) == 'r'
           ||str->at(offset) == 's'||str->at(offset) == 't'||str->at(offset) == 'u'||str->at(offset) == 'v'||str->at(offset) == 'w'||str->at(offset) == 'x'
           ||str->at(offset) == 'y'||str->at(offset) == 'z'||str->at(offset) == 'A'||str->at(offset) == 'B'||str->at(offset) == 'C'||str->at(offset) == 'D'
           ||str->at(offset) == 'E'||str->at(offset) == 'F'||str->at(offset) == 'G'||str->at(offset) == 'H'||str->at(offset) == 'I'||str->at(offset) == 'J'
           ||str->at(offset) == 'K'||str->at(offset) == 'L'||str->at(offset) == 'M'||str->at(offset) == 'N'||str->at(offset) == 'O'||str->at(offset) == 'P'
           ||str->at(offset) == 'Q'||str->at(offset) == 'R'||str->at(offset) == 'S'||str->at(offset) == 'T'||str->at(offset) == 'U'||str->at(offset) == 'V'
           ||str->at(offset) == 'W'||str->at(offset) == 'X'||str->at(offset) == 'Y'||str->at(offset) == 'Z'||str->at(offset) == '1'||str->at(offset) == '2'
           ||str->at(offset) == '3'||str->at(offset) == '4'||str->at(offset) == '5'||str->at(offset) == '6'||str->at(offset) == '7'||str->at(offset) == '8'
           ||str->at(offset) == '9'||str->at(offset) == '0'||str->at(offset) == '_')
			{
				if (offset == str->length())
					{
						return;
					}
			}*/
		
			return;
		}
		
		
	
} 

//Sets the current string to be tokenized
//Resets all Tokenizer state variables
//Calls Tokenizer::prepareNextToken() as the last statement before returning.
void Tokenizer::setString(string *str) {
	this->str=str;
	processingInlineComment=false;
    processingBlockComment=false;
    processingIncludeStatement=false;
    complete=false;
	offset=0; 
	tokenLength=0; 
	
	prepareNextToken();
	
}

//Returns the next token. Hint: consider the substr function
//Updates the tokenizer state
//Updates offset, resets tokenLength, updates processingABC member variables
//Calls Tokenizer::prepareNextToken() as the last statement before returning.
string Tokenizer::getNextToken() 
{
	string view;
	view = str -> substr(offset-tokenLength,tokenLength);
	tokenLength = 0;

	prepareNextToken();

	return view;
}

