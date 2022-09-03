// Simi Adeyemi

#include <stdio.h> 
#include <stdlib.h> 

int main(void) {

	// declaring my required variables in C

	char dashedline[] = "------------\n";
	char positivemsg[] = "Positive: %2d\n";
	char negativemsg[] = "Negative: %2d\n";
	char zeromsg[] = "Zero: %6d\n";
	int zcount;
	int pos;
	int neg;
	int num2;
	char loopQuestion[] = "Enter a number: ";
	char input2[] = "%d";
	int num;
	char Question[] = "How many numbers: ";
	char input[] = "%d";


	_asm {
		// Setting the count of pos,neg and zero to 0
		mov pos,0
		mov neg,0
		mov zcount, 0

		// Asking how many numbers the user wants to input
		lea eax, Question
		push eax
		call printf
		pop eax

		lea ecx, num
		push ecx
		lea ecx, input
		push ecx
		call scanf
		add esp, 8

		// Loop

		mov ecx, num; //Set up loop counter
		  floop :
		          push ecx; Save ecx on stack
	              lea eax, loopQuestion; //Save "Enter a number:" in EAX
			      push eax; Stack the parameter
			      call printf; Use function
			      pop eax; Remove param
			      

			      lea eax, num2
			      push eax
			      lea eax, input2
			      push eax
			      call scanf
			      add esp, 8
					  mov eax, num2
					  cmp eax, 0  // compares the number in eax to zero and jumps to category it belongs
					  jg positive
					  jz zero
					  negative :
				  add neg, 1
					  jmp endif
					  positive :
				  add pos, 1
					  jmp endif
					  zero :
				  add zcount, 1
					  endif :
					  pop ecx; 
			loop floop; 


					  lea eax, dashedline; Put address of string into eax
					  push eax; Stack the parameter
					  call printf; Use library function
					  pop eax
					  push pos; Push the int first
					  lea eax, positivemsg
					  push eax; Now stack the string
					  call printf
					  add esp, 8
					  push neg; Push the int first
					  lea eax, negativemsg
					  push eax; Now stack the string
					  call printf
					  add esp, 8
					  push zcount; Push the int first
					  lea eax, zeromsg
					  push eax; Now stack the string
					  call printf
					  add esp, 8
	}
	return 0;
}