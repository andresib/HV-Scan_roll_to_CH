#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
int main(){

 ifstream	chambers, rolls, chambers2, rolls2, alone;
  ofstream	outfile, outfile2, outfile3, outfile4;
  string	test, chambername;

  double 	wp2, position, test1, wpchamber, suma, wpc;
  char 		a[256];
  int 		offset, size, size_rolls, i=0;

  string 	rollname, rollnm6[6], name;
  double 	wp, slope50, chi2, clswp, effwp, wpDef, effWpDef, clsWpDef, effmaxerror, Serror, hv50error, emax, hv50, S;
  double 	parameter1;

  double 	mayor[6], minor, major;

  alone.open("data/Alone_chambers.txt");  
  rolls.open("data/endcap_summary.txt");
  rolls2.open("data/endcap_summary.txt");
 outfile.open("results/alone_ch_endcap.txt");
 outfile2.open("results/alone_rolls_endcap.txt");

	size_rolls=0;
	while(!rolls2.eof())					//Para calcular el tamaño del archivo de entrada rolls
	{

	rolls2>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
   	if( rolls2.eof() ) break;
	size_rolls++;

	}

	
	const int tamano_rolls = size_rolls;
	double rollwp[tamano_rolls+2];
	string *rollnm = new string[tamano_rolls+2];
	
	for(int k=0; k<tamano_rolls; k++)
	{
rolls>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
		rollnm[k]=rollname;
		rollwp[k]=wp*1000;

	}
	
	cout<<"Superada la lectura de los rolls" <<endl;



	alone>>name;
	while(!alone.eof())					
	{
	if( alone.eof() ) break;
		
	i=0;
	for(int q=0; q<tamano_rolls; q++)
		{
		offset=rollnm[q].find_last_of("_");
		
		if(rollnm[q].substr(0,offset)==name )
				{

				mayor[i]=rollwp[q];
				rollnm6[i]=rollnm[q];
				cout<<rollnm[q]<<" "<<endl;
				cout<<rollwp[q]<<" "<<endl;
				cout<<i<<" "<<endl;							
				i++;
				
				
				}
		}

		suma=0;
		minor=mayor[0];
		major=mayor[0];
		for(int n=0; n<i; n++)
		{
		minor=min(minor,mayor[n]);
		major=max(major,mayor[n]);
		suma=mayor[n]+suma;
		}
		wpc = (major > minor+100)? minor+100 : suma/i;

		
		outfile<<name<<"\t"<<major-minor<<"\t"<<wpc<<"\t"<<endl;

				outfile2<<major-minor<<"\t"<<wpc<<"\t";
				
				for(int p=0; p<i; p++)
					{
					outfile2<<rollnm6[p]<<" "<<mayor[p]<<" ";
					}
				outfile2<<endl;


   				
   	
	alone>>name;

	}
    
     delete [] rollnm;
  outfile.close();
  outfile2.close();
  rolls.close();
  rolls2.close();
  alone.close();
  


return 0;




}
