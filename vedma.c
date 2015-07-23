/*
 * vestkyne pro Adama
 * wykys 2015
 * verze: 1.0
 * program se snazi uhodnout, na ktere cislo uzivatel mysli
 * ovladani:
 * souhlas pomoci: A, a, J, j, Y, y
 * nesouhlas pmoci libololneho jineho znaku napr.: N, n
 * potvrzeni odpovedi pomoci klavesy Enter
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>


// pokud je hadane cislo vesti nez parametr
// tak vrati true
char vstup(int cislo)
{
	char in;
	printf("  Je tve cislo > nez %d: ", cislo);
	
	while ( (in=getchar()) == '\n')
		;
		
	return (in=='Y' || in=='y' || in=='J' || in=='j' || in=='A' || in=='a') ? 1 : 0;
}

// rozhodne, zda-li uz vi na ktere cislo uzivatel mysli
// pokud to jeste nevi, tak se rekurzivne vola tak dlouho
// dokud na to neprijde
// zobrazuje informacni vypisy, aby se lepo sledoval postup algoritmu
// vraci cislo, ktere si uzivatel mysli
int zjisti(int cislo, int min, int max, int old)
{
	int zjisteno = 0;
	
	printf("                                -------------------------------------\n");
	printf("                                %d cislo, %d min, %d max, %d odl\n", cislo, min, max, old);
	printf("                                -------------------------------------\n");	
	
	if (min > max)
	{
		return 0;
	}
	
	if (min == max)
	{
		printf("  Heureka!\n");
		return cislo;
	}
		
	old = cislo;
	
	if (vstup(cislo))
	{
		min = cislo+1;
		cislo += (max-cislo)/2;
		if (cislo == old)
		{
			cislo++;
		}
		zjisteno = zjisti(cislo, min, max, old);
	}
	else
	{
		max = cislo;
		cislo -= (cislo-min)/2;
		if (cislo == old && cislo==2)
		{			
			cislo--;
		}
		zjisteno = zjisti(cislo, min, max, old);
	}
	
	
	return zjisteno;
}

// hlavni funkce
// zavola zjistovaci funkci
// graficky pomoci TUI imterpretuje vysledky
void main(void)
{ 
	int cislo = 0;
	
	printf("=====================================================================\n");
	printf("  wykys 2015                                                         \n");
	printf(".....................................................................\n");
	printf("  Mysli si cele cislo <1; 100> a odpovidej na otazka Y or N          \n");
	printf("=====================================================================\n");

	if ( (cislo=zjisti(50, 1, 100, -1)) )
	{
		printf("*********************************************************************\n");
		printf("  Tvoje cislo je %d.\n", cislo);
		printf("*********************************************************************\n");
	}
	else
	{
		printf("*********************************************************************\n");
		printf("  Podvadis, seru na tebe zmrde.                                      \n");
		printf("*********************************************************************\n");  
	}
}
