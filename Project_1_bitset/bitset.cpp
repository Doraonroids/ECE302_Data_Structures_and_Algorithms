#include "bitset.hpp"


Bitset::Bitset(){
	validity = 1;
	N = 8;
	bit_array = new int[N];
	for(int i = 0; i < N; i++){
		*(bit_array + i) = 0;
	}
	
}


Bitset::Bitset(int size){
	validity = 1;
	N = size;
	if(N >= 0){
		bit_array = new int[N];
		for(int i = 0; i < N; i++){
			*(bit_array + i) = 0;
		}
	}else{
		N = 0;
		bit_array = new int[N];
		validity = 0;
		//error message and exit?
	}
}


Bitset::Bitset(const std::string & value){
	validity = 1;
	N = value.length();
	bit_array = new int[N];
	for(int i = 0; i < N; i++){
		if (value[i] == 0 || value[i] == 1) {
			*(bit_array + i) = (value[i]);//stoi?
		}else{
			validity = 0;
			//error message and exit?
		}
	}
}
// TODO


  // TODO COMMENT
Bitset::~Bitset(){
	delete[] bit_array;
}
	

// TODO COMMENT
int Bitset::size() const{
	return N;
}

// TODO COMMENT
bool Bitset::good() const{
	if (validity) {
		for (int i = 0; i < N; i++) {
			if (*(bit_array + i) != 0 && *(bit_array + i) != 1) {
				return 0;
			}
		}
	}
	else {
		return validity;
	}
	return 1;
}

// TODO COMMENT
void Bitset::set(int index){
	if (index >= 0 && index <= N) {
		*(bit_array + index) = 1;
	}else{
		validity = 0;
		//bit_set invalid error
	}
}

// TODO COMMENT
void Bitset::reset(int index){
	if (index >= 0 && index <= N) {
		*(bit_array + index) = 0;
	}else{
		validity = 0;
		//bit_set invalid error
	}
}

// TODO COMMENT
void Bitset::toggle(int index) {
	if (index >= 0 && index <= N) {
		if (*(bit_array + index) == 0) {
			*(bit_array + index) = 1;
		}else{
			*(bit_array + index) = 0;
		}
	}else{
		validity = 0;
		//bit_set invalid error
	}
	
}

// TODO COMMENT
bool Bitset::test(int index){
	if (index >= 0 && index <= N) {
		if (*(bit_array + index) == 1) {
			return 1;
		}else{
			return 0;
		}
	}else{
		validity = 0;
		return 0;
		//bit_set invalid error
	}
}

// TODO COMMENT
std::string Bitset::asString() const{
	std::string bits = "";
	for (int i = 0; i < N; i) {
		bits += std::to_string(*(bit_array + i));
	}
	return bits;
}

