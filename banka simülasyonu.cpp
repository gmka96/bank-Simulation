#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int kuyruk_sayisi = 0, kuyruk_say = 0, gise_no;
struct musteri
{
	int i_sure;  //iþlem suresi
	int sira_no;
	int g_sure;  //geldiði sure
	int bekleme_suresi;
	int gise_no;
	int cikis;
	musteri *ileri;
};
musteri *head, *p, *g;

struct giseler {
	int musteri_s;
	int toplam_sure;
	int zaman;
};
giseler gise[3];
typedef struct musteri musteri;
typedef struct giseler giseler;
void zaman_siralama();
void gun_sonu();
void kuyruk(int similasyon_sure);
int islemler(int secim);
int islem(musteri *p);
int main()
{
	system("color 0b");
	int similasyon_sure, cekirdek_deger, i;
	printf("SIMILASYON SURESINI GIRINIZ:");   scanf("%d", &similasyon_sure);
	printf("CEKIRDEK DEGER GIRINIZ:");   scanf("%d", &cekirdek_deger);
	srand(cekirdek_deger);
	kuyruk(similasyon_sure);
	for (i = 0; i<3; i++)
	{
		gise[i].musteri_s = 0;
		gise[i].toplam_sure = 0;
		gise[i].zaman = 0;
	}
	zaman_siralama();
	gun_sonu();
	_getch();


}
int islem(musteri *p)
{
	int i, enAz_sure, islem_zamani;
    if (gise[0].zaman <= p->g_sure)
	{
		if(p->sira_no%2==0)
			printf("#%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 1);
		else
		printf("%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 1);
		gise[0].musteri_s++;
		islem_zamani = islemler(rand() % 3);
		gise[0].toplam_sure += islem_zamani;
		gise[0].zaman = islem_zamani + p->g_sure;
		if(p->sira_no%2==0)
			printf("#%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 1, islem_zamani);
		else
			printf("%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 1, islem_zamani);
        p->gise_no = 1;
		p->cikis = gise[0].zaman;
		return gise[0].zaman;
	}
	else if (gise[1].zaman <= p->g_sure)
	{
		if (p->sira_no % 2 == 0)
			printf("#%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 2);
		else
			printf("%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 2);
		gise[1].musteri_s++;
		islem_zamani = islemler(rand() % 3);
		gise[1].toplam_sure += islem_zamani;
		gise[1].zaman = islem_zamani + p->g_sure;
		if (p->sira_no % 2 == 0)
			printf("#%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 2, islem_zamani);
		else
			printf("%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 2, islem_zamani);
		p->gise_no = 2;
		p->cikis = gise[1].zaman;
		return gise[1].zaman;
	}
	else if (gise[2].zaman <= p->g_sure)
	{
		if (p->sira_no % 2 == 0)
			printf("#%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 3);
		else
			printf("%d.MUSTERI->%d.DAKIKADA -> %d.GISEYE GIRIS YAPTI\n", p->sira_no, p->g_sure, 3);
		gise[2].musteri_s++;
		islem_zamani = islemler(rand() % 3);
		gise[2].toplam_sure += islem_zamani;
		gise[2].zaman = islem_zamani + p->g_sure;
		if (p->sira_no % 2 == 0)
			printf("#%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 3, islem_zamani);
		else
			printf("%d.MUSTERI -> %d.GISEDE -> %d DK ISLEM YAPACAK \n", p->sira_no, 3, islem_zamani);
		p->gise_no = 3;
		p->cikis = gise[2].zaman;
		return gise[2].zaman;
	}
	else
	{
		enAz_sure = gise[0].zaman;
		for (i = 0; i < 3; i++)
		{
			if (gise[i].zaman < enAz_sure)
				enAz_sure = gise[i].zaman;
		}
		p->bekleme_suresi = enAz_sure - p->g_sure;
		if(p->sira_no%2==0)
			printf("#%d.MUSTERI BEKLIYOR %d DK BEKLEDI\n", p->sira_no, p->bekleme_suresi);
		else
			printf("%d.MUSTERI BEKLIYOR %d DK BEKLEDI\n", p->sira_no, p->bekleme_suresi);
		p->g_sure += p->bekleme_suresi;
		return 1;
	}




}
void kuyruk(int similasyon_sure) {
	int toplam_sure = 0;
	musteri *g;

	for (kuyruk_sayisi = 0; kuyruk_sayisi < 100; kuyruk_sayisi++)
	{
		g = p;
		if (kuyruk_sayisi == 0)
		{
			head = (musteri *)malloc(sizeof(musteri));
			p = head;
		}
		else
		{
			p->ileri = (musteri *)malloc(sizeof(musteri));
			p = p->ileri;
		}
		p->g_sure = toplam_sure + rand() % 5;
		p->sira_no = kuyruk_sayisi + 1;
		toplam_sure = p->g_sure;
		p->bekleme_suresi = 0;
		p->gise_no = 0;
		if (toplam_sure >= similasyon_sure)
			break;
	}
	p->ileri = NULL;

	if (p->g_sure >= similasyon_sure)
	{
		toplam_sure -= (p->g_sure - g->g_sure);
		g->ileri = p->ileri;
		free(p);
	}
	p = head;

}
int zaman;
void zaman_siralama() {
	p = head;
	g = p;
	do
	{
		g = p->ileri;
		zaman = islem(p);
		if (zaman == 1)
		continue;
		if (g->g_sure < zaman)
		{
			if(g->sira_no%2==0)
				printf("#%d.MUSTERI -> %d.DAKIKADA GIRIS YAPTI\n", g->sira_no, g->g_sure);
			else
				printf("%d.MUSTERI -> %d.DAKIKADA GIRIS YAPTI\n", g->sira_no, g->g_sure);
         }
		if(p->sira_no%2==0)
			printf("#%d.MUSTERI -> %d.DAKIKADA ->%d.GISEYI TERKETTI\n", p->sira_no, p->cikis, p->gise_no);
		else
			printf("%d.MUSTERI -> %d.DAKIKADA ->%d.GISEYI TERKETTI\n", p->sira_no, p->cikis, p->gise_no);
    p = p->ileri;
		
	} while (g != NULL);
	islem(p);
	if(p->sira_no%2==0)
		printf("#%d.MUSTERI -> %d.DAKIKADA ->%d.GISEYI TERKETTI\n", p->sira_no, p->cikis, p->gise_no);
	else
		printf("%d.MUSTERI -> %d.DAKIKADA ->%d.GISEYI TERKETTI\n", p->sira_no, p->cikis, p->gise_no);



}
void gun_sonu()
{
	int bekleyen = 0, enCok_bekleyen = 0, topBek_suresi = 0, i;
	float ortalama, islem_ort = 0;;
	p = head;
	while (p != NULL)
	{
		if (p->bekleme_suresi != 0)
		{
			topBek_suresi += p->bekleme_suresi;
			bekleyen++;
			if (p->bekleme_suresi > enCok_bekleyen)
				enCok_bekleyen = p->bekleme_suresi;
		}
		p = p->ileri;
	}
	if (bekleyen == 0)
		ortalama = 0.0;
	else
		ortalama = bekleyen / (float)topBek_suresi;
	printf("********************************* GUN SONU *******************************************************\n");
	printf("%d KISI KUYRUKTA BEKLEDI\nEN UZUN %d DAKIKA BEKLENDI\n%.2f DAKIKA ORTALAMA KUYRUK BEKLEME SURESI\n\n", bekleyen, enCok_bekleyen, ortalama);
	printf("**************************************************************************************************\n");
	printf("GISE\t\t\tHIZMET VERILEN KISI SAYISI\t\t\tORTALAMA HIZMET SURESI\t\t\tTOPLAM HIZMET SURESI\n");
	for (i = 0; i < 3; i++)
	{
		islem_ort = gise[i].musteri_s / (float)gise[i].toplam_sure;
		printf("%d\t\t\t\t%d\t\t\t\t\t\t%.2f\t\t\t\t\t%d\n", i + 1, gise[i].musteri_s, islem_ort, gise[i].toplam_sure);
	}
}
int islemler(int secim) {
	switch (secim) {
	case 0:
	{
		int eft = 3 + rand() % 7;
		return eft;

	}
	break;
	case 1:
	{
		int kredi_cekme = 10 + rand() % 10;
		return kredi_cekme;

	}
	break;
	case 2:
	{
		int fatura = 2 + rand() % 10;
		return fatura;

	}
	break;
	case 3:
	{
		int para_cekme = 1 + rand() % 6;
		return para_cekme;

	}

	}
}
