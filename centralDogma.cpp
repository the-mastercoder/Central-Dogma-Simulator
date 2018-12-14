//Central Dogma: DNA->RNA->Protein
//This program transcript and translate dna into protein.

/*
Bio part:: DNA only contains 4bases Adenine(a),Guanine(g),;
Cytosine(c),Thymine(t),so the dna template should only be the combination of these segments
*/

//Written by: MasterCoder
//Insta: the_mastercoder
//Dated: 14-NOV-MMXV111

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dnaTemplateModulator(int);
string codonTable(char,char,char);

int main()
{
	cout<<"Central Dogma Simulator\n";
	cout<<"Written by Anu Panicker\n\n";
	for(;;)
	{
	string dnaTemplate;
	cout<<"Type in the template codons: ";
	getline (cin,dnaTemplate);
	if (dnaTemplate.find_first_not_of("agtc")==string::npos)
	{ dnaTemplate.erase(dnaTemplate.end()-dnaTemplateModulator(dnaTemplate.size()),dnaTemplate.end());	transform(dnaTemplate.begin(),dnaTemplate.end(),dnaTemplate.begin(),::toupper);
	
	vector <char> transcription;    copy(dnaTemplate.begin(),dnaTemplate.end(),back_inserter(transcription));
	for(int n_base=0;n_base<dnaTemplate.size();++n_base)
	{	
	if(transcription.at(n_base)=='A')
	{transcription.at(n_base)='U';}
    else if(transcription.at(n_base)=='T')
    {transcription.at(n_base)='A';}
	else if(transcription.at(n_base)=='G')
	{transcription.at(n_base)='C';}
	else if(transcription.at(n_base)=='C')
	{transcription.at(n_base)='G';}
	}
string rnaTemplate(transcription.begin(),transcription.end());
	cout<<"DNA Template:"<<"5'- "<<dnaTemplate<<" -3'"<<endl;
	cout<<"RNA Template:"<<"5'- "<<rnaTemplate<<" -3'"<<endl;
	cout<<endl;
	
	vector <string> geneticCode;
	for(int triplet=0;triplet<(rnaTemplate.size());triplet+=3)
	{geneticCode.push_back((rnaTemplate.substr(triplet,3)));}
    string codon; codon.resize(3);
    vector <char> bases;
    cout<<"Protein: ";
for(int aminoacid=0;aminoacid<geneticCode.size();++aminoacid)
	{
		codon=geneticCode.at(aminoacid);
		copy(codon.begin(),codon.end(),back_inserter(bases));
		
	if(aminoacid==0)
	{cout<<codonTable(bases[0],bases[1],bases[2]);}
	else if(aminoacid>0&&aminoacid<geneticCode.size())	        {cout<<"-"<<codonTable(bases[0],bases[1],bases[2]);}
	else if(aminoacid!=0&&aminoacid==geneticCode.size())
	{cout<<"-"<<codonTable(bases[0],bases[1],bases[2]);}
			bases.clear();
		}
		cout<<endl<<endl;
	}
	else {cout<<"Invalid DNA template\n";}
	};

	return 0;
}

int dnaTemplateModulator(int d_tempSize)
{
	if(d_tempSize%3 == 0){return 0;}
	else if(((d_tempSize-1)%3 && (d_tempSize+2)%3) == 0){return 1;}
	else if(((d_tempSize+1)%3 && (d_tempSize-2)%3) == 0){;return 2;}
}

string codonTable(char _base1,char _base2,char _base3)
{

typedef vector<string> base_1;
typedef vector<base_1> base_2;
typedef vector<base_2> base_3;
base_3 codon{4,base_2{4,base_1{4}}};

enum bases{U=0,C=1,A=2,G=3};
bases _base1_,_base2_,_base3_;

if(_base1=='U'){_base1_=U;}
else if(_base1=='C'){_base1_=C;}
else if(_base1=='A'){_base1_=A;}
else if(_base1=='G'){_base1_=G;}

if(_base2=='U'){_base2_=U;}
else if(_base2=='C'){_base2_=C;}
else if(_base2=='A'){_base2_=A;}
else if(_base2=='G'){_base2_=G;}

if(_base3=='U'){_base3_=U;}
else if(_base3=='C'){_base3_=C;}
else if(_base3=='A'){_base3_=A;}
else if(_base3=='G'){_base3_=G;}

codon[U][U][U]="Phe";codon[U][C][U]="Ser";
codon[U][A][U]="Try";codon[U][G][U]="Cys";
codon[U][U][C]="Phe";codon[U][C][C]="Ser";
codon[U][A][C]="Tyr";codon[U][G][C]="Cys";
codon[U][U][A]="Leu";codon[U][C][A]="Ser";
codon[U][A][A]="|STOP|";codon[U][G][A]="|STOP| ";
codon[U][U][G]="Leu";codon[U][C][G]="Ser";
codon[U][A][G]="|STOP|";codon[U][G][G]="Trp";
codon[C][U][U]="Leu";codon[C][C][U]="Pro";
codon[C][A][U]="His";codon[C][G][U]="Arg";
codon[C][U][C]="Leu";codon[C][C][C]="Pro";
codon[C][A][C]="His";codon[C][G][C]="Arg";
codon[C][U][A]="Leu";codon[C][C][A]="Pro";
codon[C][A][A]="Gln";codon[C][G][A]="Arg";
codon[C][U][G]="Leu";codon[C][C][G]="Pro";
codon[C][A][G]="Gln";codon[C][G][G]="Arg";
codon[A][U][U]="Ile";codon[A][C][U]="Thr";
codon[A][A][U]="Asn";codon[A][G][U]="Ser";
codon[A][U][C]="Ile";codon[A][C][C]="Thr";
codon[A][A][C]="Asn";codon[A][G][C]="Ser";
codon[A][U][A]="Ile";codon[A][C][A]="Thr";
codon[A][A][A]="Lys";codon[A][G][A]="Arg";
codon[A][U][G]="Met";codon[A][C][G]="Thr";
codon[A][A][G]="Lys";codon[A][G][G]="Arg";
codon[G][U][U]="Val";codon[G][C][U]="Ala";
codon[G][A][U]="Asp";codon[G][G][U]="Gly";
codon[G][U][C]="Val";codon[G][C][C]="Ala";
codon[G][A][C]="Asp";codon[G][G][C]="Gly";
codon[G][U][A]="Val";codon[G][C][A]="Ala";
codon[G][A][A]="Glu";codon[G][G][A]="Gly";
codon[G][U][G]="Val";codon[G][C][G]="Ala";
codon[G][A][G]="Glu";codon[G][G][G]="Gly";

return codon[_base1_][_base2_][_base3_];
}