#pragma once
#ifndef AB_H
#define AB_H

//tip de data generic(pentru moment este intreg)
typedef int TElem;

class Nod;

class Iterator;

typedef Nod *PNod;

class Nod
{
public:
	friend class AB;
	friend class Iterator;
	Nod(TElem e, PNod st, PNod dr);

private:
	TElem e;
	PNod st, dr;
};

//tipul unui pointer spre o functie folosit pt vizitarea nodurilor arborelui
typedef void(*PFunctie)(TElem);

//clasa care defineste reprezentarea si functiile TAD Arbore Binar

class AB {
private:
	PNod rad;
	
	//functia recursiva pt distrugerea arborelui
	void distruge(PNod);

	void distrugeSubarbori(PNod);

	//copiere subarbore
	PNod copiere(PNod) const;

	//prelucrare recursiva
	void visit(PNod, PFunctie);

public:
	AB();

	friend class Iterator;
	//friend class Nod;

	//construcor copiere
	AB(const AB&);

	//creeaza un arbore binar care se reduce la o frunza
	void creeazaFrunza(TElem elem);

	//constructor arbore binar
	void creeazaAB(const AB& st, TElem e, const AB& dr);

	//adauga unui arbore binar subarborele stang
	void adaugaSubSt(const AB& st);
	//adauga unui arbore binar subarborele drept
	void adaugaSubDr(const AB& dr);
	//verofica daca arborele este vid
	bool vid() const;
	//accesare element din radacina
	TElem element() const;
	//accesare subarbore stang
	AB stang() const;
	//accesare subarbore drept
	AB drept() const;

	Iterator radi() const;

	//prelucrarea nodurilor din arbore
	void visitTree(PFunctie);

	void BFS();
	void preorder(PNod p);
	void callPre();
		// destructorul arborelui binar
	~AB();
};

class SuccessorIteration {
	/*
	class Node {
		final Node left;
		final Node right;
		final int key;
		Node parent;
		Node(int key, Node left, Node right) {
			this.key = key;
			this.left = left;
			this.right = right;
			if (left != null) left.parent = this;
			if (right != null) right.parent = this;
		}
		*/
public:
	friend class AB;
		Nod getLeftMost() {
			Nod n = this;
			while (n->st != NULL) {
				n = n->st;
			}
			return n;
		}
		Node getNext() {
			if (right != null) {
				return right.getLeftMost();
			}
			else {
				Node n = this;
				while (n.parent != null && n == n.parent.right) {
					n = n.parent;
				}
				return n.parent;
			}
		}
	}
}
#endif