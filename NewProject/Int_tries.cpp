#include "Int_tries.h"
Nose::Nose() {
	z = o = nullptr;
	count = 0;
}
ll_tire::ll_tire() {
	emshe = root = new Nose();
}
ll_tire::~ll_tire() {
	free_memory(root);
}
void ll_tire::free_memory(Nose *cur) {
	if (cur == nullptr) {
		return;
	}
	while (cur->count) {
		cur->count--;
		std::cout << cur->v << std::endl;
	}
	free_memory(cur->z);
	free_memory(cur->o);
	delete cur;
}
int ll_tire::get_freq(long long input) {
	search_node(input);
	int ret = emshe->count;
	emshe = root;
	return ret;
}
void ll_tire::del(long long input) {
	search_node(input);
	emshe->count--;
	if (emshe->count<0) {
		emshe->count++;
	}
	emshe = root;
}
void ll_tire::insert(long long input) {
	search_node(input);
	emshe->count++;
	emshe->v = input;
	emshe = root;
}
void ll_tire::search_node(long long input) {
	for (long long i = 63, one = 1; i >= 0; i--) {
		if (emshe->o == nullptr) {
			emshe->o = new Nose();
		}
		if (emshe->z == nullptr) {
			emshe->z = new Nose();
		}
		if (input&(one << i)) {
			emshe = emshe->o;
		}
		else {
			emshe = emshe->z;
		}
	}
}