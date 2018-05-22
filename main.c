#include <stdio.h>
#include <stdlib.h>
int main()
{
    ///========================================================ENKRIPSI=============================
    char plan[100], key[100], chipper[100]="";
    char abjad[26]="abcdefghijklmnopqrstuvwxyz";
    char temp;
    int a, b, i, j, turun;

    printf("=====================PROGRAM ENKRIPSI DAN DEKRIPSI======================\n\n");
    printf("masukkan plantext : "); gets(&plan);
    printf("masukkan key text : "); gets(&key);

    ///menghitung panjang key dan plan text
    a = strlen(key);
    b = strlen(plan);

    ///lower case untuk plain dan key text
    for(i=0; i<b; i++) plan[i]=tolower(plan[i]);
    for(i=0; i<a; i++) plan[i]=tolower(key[i]);

    ///menghilangkan space pada string plan
    for(i=0; i<b; i++)
    {
        for(j=0; j<b; j++){
            if(plan[j] == ' ')
            {
                temp = plan[j];
                plan[j] = plan[j+1];
                plan[j+1] = temp;
            }
        }
    }

    ///menggabungkan space pada string key
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++){
            if(key[j] == ' ')
            {
                temp = key[j];
                key[j] = key[j+1];
                key[j+1] = temp;
            }
        }
    }

    ///menghitung panjang key dan plan text setelah menghilangkan space
    a = strlen(key);
    b = strlen(plan);

    ///menghitung urutan array key
    int panjang[a];
    int angka=1;
    for(i=0; i<26; i++)
    {
        for(j=0; j<a; j++)
        {
            if(abjad[i]==key[j])
            {
                panjang[j]=angka;
				angka++;
            }
        }
    }

    ///mencetak urutan key
    printf("urutan key : ");
    for(i=0; i<a; i++)
    {
        printf("%d ", panjang[i]);
    }
    printf("\n\n\n");
    printf("============================= ENKRIPSI ==============================\n\n");
    ///mengidentifikasi panjang matrik menurun
    if(strlen(plan)%a==0){
        turun = b/a;
    }else{
        turun=b/a+1;
    }

    ///membuat string matrik
    int k=0;
    char matrik[turun][a];
    for(i=0; i<turun; i++)
    {
        for(j=0; j<a; j++)
        {
            if(k<b){
                matrik[i][j] = plan[k];
            }else{
                matrik[i][j] = ' ';
            }
            k++;
        }
    }

    ///mencetak matrik
    printf("==MATRIK ENKRIPSI==\n");
    for(i=0; i<turun; i++)
    {
        for(j=0; j<a; j++)
        {
            printf("%c ", matrik[i][j]);
        }
        printf("\n");
    }



    ///membuat chipper
    angka=1;
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            if(panjang[j]==angka)
            {
                for(k=0; k<turun; k++)
                {
                    if(matrik[k][j]!=' ')
                    {
                        int P = strlen(chipper);
                        chipper[P]=matrik[k][j];
                    }
                }
                angka++;
            }
        }
    }

    ///output chipper text
    printf("\n\nChipper text adalah : %s\n\n\n\n", chipper);
    printf("============================= DEKRIPSI ==============================\n\n");


    ///========================================================DEKRIPSI=============================
    printf("==MATRIK DEKRIPSI==\n");
    ///membuat matrik dekripsi
    char matrikdone[turun][a];
    angka=1;
    int urut=0;
    int kosong = a-((turun*a)%b);
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            if(panjang[j]==angka)
            {
                if(j>=kosong)
                {
                    for(k=0; k<turun; k++)
                    {
                        if(k!=turun-1)
                        {
                            matrikdone[k][j] = chipper[urut];
                            urut++;
                        }else
                        {
                            matrikdone[k][j] = ' ';
                        }
                    }
                }else
                {
                    for(k=0; k<turun; k++)
                    {
                        matrikdone[k][j] = chipper[urut];
                        urut++;
                    }
                }
                angka++;
            }
        }
    }

    ///mencetak matrik hasil dekripsi
    for(i=0; i<turun; i++)
    {
        for(j=0; j<a; j++)
        {
            printf("%c ", matrikdone[i][j]);
        }
        printf("\n");
    }

    fflush(stdin);
    ///membuat string dari matrik dekripsi
    int jumlah = turun*a-((turun*a)%b);
    urut = 0;
    char plandone[100]="";
    for(i=0; i<turun; i++)
    {
        for(j=0; j<a; j++)
        {
            plandone[urut] = matrikdone[i][j];
            urut++;
        }
    }

    ///mencetak string hasil dekripsi
    printf("\nHasil deskripsi adalah : %s\n", plandone);

    return 0;
}
