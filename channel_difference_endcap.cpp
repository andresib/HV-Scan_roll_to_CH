#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
int main(){
  ifstream	chambers, rolls, chambers2, rolls2;
  ofstream	outfile, outfile2, outfile3, outfile4;
  string	test, chambername;

  double 	wp2, position, test1, wpchamber, suma, wpc;
  char 		a[256];
  int 		offset, size, size_rolls, i=0;

  string 	rollname, rollnm6[6], name;
  double 	wp, slope50, chi2, clswp, effwp, wpDef, effWpDef, clsWpDef, effmaxerror, Serror, hv50error, emax, hv50, S;
  double 	parameter1;

  double 	mayor[6], minor, major;


  outfile.open("results/roll_difference_endcap.txt");
  outfile2.open("results/Alone_endcap.txt");
  outfile3.open("results/ch_diference_endcap.txt");
  outfile4.open("results/menos_rolls_endcap.txt");
  chambers.open("data/AveragedAll.txt");  
  chambers2.open("data/AveragedAll.txt"); 
  //alone.open("data/Alone_chambers.txt");  
  //alone2.open("data/Alone_chambers.txt"); 
  rolls.open("data/endcap_summary.txt");
  rolls2.open("data/endcap_summary.txt");
 
  		if(!chambers)	cout<<"data/Ideal.txt do not exist"<<endl;
  		if(!rolls)	cout<<"WARNING Combineda.txt do not exist"<<endl;


	size=0;
	while(!chambers2.eof())					//Para calcular el tamaño del archivo de entrada chambers
	{
	//getline(chambers2, test);				//cualquiera de las opciones anteriores se puede usar para saltar de linea:
	chambers2>>test>>test1;					//getline(chambers2, test);   or    chambers2>>test>>test1;	
   	if( chambers2.eof() ) break;
	size++;

	}

	
	const int tamano_chambers = size;
	double wps[tamano_chambers];
	string *cns= new string[tamano_chambers];
    

	
	for(int l=0; l<tamano_chambers; l++)
	{
		chambers>>chambername>>wpchamber;	
		cns[l]=chambername;
		wps[l]=wpchamber;

	}

	size_rolls=0;
	while(!rolls2.eof())					//Para calcular el tamaño del archivo de entrada rolls
	{

	rolls2>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
   	if( rolls2.eof() ) break;
	size_rolls++;

	}

	
	const int tamano_rolls = size_rolls;
	double rollwp[tamano_rolls];
	string *rollnm = new string[tamano_rolls];
    
 
	
	for(int k=0; k<tamano_rolls; k++)
	{
rolls>>rollname>>wp>>slope50>>emax>>hv50>>chi2>>clswp>>effwp>>wpDef>>effWpDef>>clsWpDef>>effmaxerror>>Serror>>hv50error>>S>>parameter1;
		rollnm[k]=rollname;
		rollwp[k]=wp*1000;

	}






	for(int j=0; j<tamano_chambers; j++)
		{

			
			if(wps[j]==wps[j+1])
			{

			i=0;
			//minor=1000000000;
			//major=0;
  				for(int m=0; m<tamano_rolls; m++)
				{

		
    					

		
				offset=rollnm[m].find_last_of("_");

				
		if(rollnm[m].substr(0,offset)==cns[j].substr(0,offset) || rollnm[m].substr(0,offset)==cns[j+1].substr(0,offset) )
				{
				
				
				//outfile<<rollnm[m]<<"\t"<<wps[j]<<"\t"<<rollwp[m]<<endl;
				mayor[i]=rollwp[m];
				rollnm6[i]=rollnm[m];



				//if(rollwp[m]>major)
   				//major=rollwp[m];
				//if(rollwp[m]<minor)
   				//minor=rollwp[m];
				
				
  				//cout<<i<<" "<<mayor[i]<<" "<<minor<<" "<<major<<endl;
  				//cout<<i<<endl;
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

				outfile<<major-minor<<"\t"<<wpc<<"\t";
				
				for(int p=0; p<i; p++)
					{
					outfile<<rollnm6[p]<<" "<<mayor[p]<<" ";
					}
				outfile<<endl;
			
			
			outfile3<<cns[j]<<"\t"<<major-minor<<"\t"<<wpc<<endl;




			//outfile3<<cns[j]<<" "<<cns[j+1]<<" "<<major-minor<<" "<<wps[j]<<endl;
			if(i<5)  outfile4<<cns[j]<<" "<<cns[j+1]<<endl;



			j=j+1;


			}
			else
			{
			outfile2<<cns[j]<<endl;

			}





		}











  		
    delete [] cns;
    
    delete [] rollnm;
   



  outfile.close();
  outfile2.close();	
  outfile3.close();
  outfile4.close();
  rolls.close();
  rolls2.close();
  chambers.close();
  chambers2.close();

return 0;

}
