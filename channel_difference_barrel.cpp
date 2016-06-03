#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
int main(){
  ifstream	rolls, rolls2;
  ofstream	outfile, outfile2, outfile3, outfile4;
  string	test, chambername;

  double 	wpc, position, rest, test1, wpchamber;
  char 		a[256];
  int 		offset, size, size_rolls, i=0;

  string 	rollname;
  double 	wp, slope50, chi2, clswp, effwp, wpDef, effWpDef, clsWpDef, effmaxerror, Serror, hv50error, emax, hv50, S;
  double 	parameter1;

  double 	mayor[6], minor, major;


  outfile.open("results/roll_difference_barrel.txt");
  outfile2.open("results/Alone_chamber_barrel.txt");
  outfile3.open("results/ch_diference_barrel.txt");
  outfile4.open("results/con3_rolls_barrel.txt");
  rolls.open("data/barrel_summary.txt");
  rolls2.open("data/barrel_summary.txt");
 

  if(!rolls)	cout<<"WARNING barrel_summary.txt do not exist"<<endl;




	size_rolls=0;
	while(!rolls2.eof())					//Para calcular el tamaño del archivo de entrada rolls
	{

	rolls2>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
   	if( rolls2.eof() ) break;
	size_rolls++;

	}

	
	const int tamano_rolls = size_rolls;
	double rollwp[tamano_rolls+2];
	//string rollnm[tamano_rolls+2];
    string *rollnm = new string[tamano_rolls+2];
    

	
	for(int k=0; k<tamano_rolls; k++)
	{
rolls>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
		rollnm[k]=rollname;
		rollwp[k]=wp*1000;

	}
	
	cout<<"Superada la lectura de los rolls" <<endl;
	
 	for(int m=0; m<tamano_rolls; m++)
	{
	offset=rollnm[m].find_last_of("_");
	//cout<<rollnm[m].substr(offset+1)<<endl;
	minor=rollwp[m];
	major=rollwp[m];

		if (rollnm[m].substr(0,offset)==rollnm[m+1].substr(0,offset))      //checks if roll1 and roll2 belong to same chamber
		{
		minor=min(minor,rollwp[m+1]);
		major=max(major,rollwp[m+1]);

		 	if (rollnm[m].substr(0,offset)==rollnm[m+2].substr(0,offset)) //checks if roll1 and roll3 belong to sm chamber
			{
			minor=min(minor,rollwp[m+2]);
			major=max(major,rollwp[m+2]);
			
			wpc = (major > minor+100)? minor+100 : (rollwp[m]+ rollwp[m+1] + rollwp[m+2])/3;	

			
			outfile<<rollnm[m].substr(0,offset)<<"\t"<<major-minor<<"\t"<<wpc<<"\t"<<rollnm[m].substr(offset+1)<<" ";
			outfile<<rollwp[m]<<" "<<rollnm[m+1].substr(offset+1)<<" "<<rollwp[m+1]<<" ";
			outfile<<rollnm[m+2].substr(offset+1)<<" "<<rollwp[m+2]<<endl;
			outfile3<<rollnm[m].substr(0,offset)<<"\t"<<major-minor<<"\t"<<wpc<<endl;
			outfile4<<rollnm[m].substr(0,offset)<<endl;			
			m++;

			}
			else 
			{
			wpc = (major > minor+100)? minor+100 : (rollwp[m]+ rollwp[m+1] )/2;
			outfile<<rollnm[m].substr(0,offset)<<"\t"<<major-minor<<"\t"<<wpc<<"\t"<<rollnm[m].substr(offset+1)<<" ";
			outfile<<rollwp[m]<<" "<<rollnm[m+1].substr(offset+1)<<" "<<rollwp[m+1]<<endl;
			outfile3<<rollnm[m].substr(0,offset)<<"\t"<<major-minor<<"\t"<<wpc<<endl;
						
			}
		m++;	

		}
		else
		{
		outfile2<<rollnm[m]<<endl;
		}
		
    					

	}	
				

				
	



	






		







  	
    delete [] rollnm;


  outfile.close();
  outfile2.close();	
  outfile3.close();
  outfile4.close();
  rolls.close();
  rolls2.close();


return 0;

}
