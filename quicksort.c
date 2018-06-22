#include <stdio.h>
#include <stdlib.h>

int total;

void cetak(int angka[])
{
	printf("\n");
	for (int i = 0; i < total - 1; i++)
		printf(" %d", angka[i]);
	printf("\n");
}

void quicksort(int angka[], int start, int pivot)
{
	int j = 0; //j adalah variabel penunjuk urutan yang dipanggil saat swap jika ada nilai yang lebih kecil dari pivot
	if (start == pivot - 1)
	{
		printf("\n");
		for (int a = start; a < pivot + 1; a++)
			printf(" %d", angka[a]);
		//printf("\n Start berada tepat sebelum pivot: ");
		if (angka[start] > angka[pivot]) //jika angka start lebih besar dari pivot, maka ditukar
			{
				int temp = angka[start];
				angka[start] = angka[pivot];
				angka[pivot] = temp;
			}
		printf("\n");
		for (int a = start; a < pivot + 1; a++)
			printf(" %d", angka[a]);
		cetak(angka);
	}
	else if (pivot > start)
	{
		printf("\n");
		for (int a = start; a < pivot + 1; a++)
			printf(" %d", angka[a]);
		//printf("\n Start bukan pivot dan bukan tepat sebelum pivot: ");
		for (int i = start; i < pivot; i++) //perulangan mulai dari start hingga pivot
		{
			if (angka[i] < angka[pivot]) //jika angka terbanding lebih kecil dari angka pivot maka angka terbanding diletakkan di posisi depan (mulai dari 0 dan selanjutnya increment)
			{
				int temp = angka[start + j];
				angka[start + j] = angka[i];
				angka[i] = temp;
				j++;
			}
			printf("\n");
			for (int a = start; a < pivot + 1; a++)
				printf(" %d", angka[a]);
		}
		int temp = angka[pivot];
		angka[pivot] = angka[start + j];
		angka[start + j] = temp;
		cetak(angka);

		if (j != 0 && start != start + j - 1) //jika start tidak sama dengan pivot
			quicksort(angka, start, start + j - 1);
		quicksort(angka, start + j + 1, pivot);
	}
	else return;
}

int main()
{
	/*printf("Masukkan jumlah angka yang ingin diurutkan: ");
	scanf("%d", &total);
	int angka[total];
	printf("\nMasukkan angka-angka tersebut: ");
	for (int i = 0; i < total; i++)
		scanf("%d", &angka[i]);
	*/
	FILE* file = fopen("data.txt", "r");
	char line[256];
	int angka[1000];
	while (fgets(line, sizeof(line), file))
	{
		angka[total] = atoi(line);
        	total++;
    	}

	quicksort(angka, 0, total - 2);
	printf("\nHasil quick sort: ");
	cetak(angka);
	fclose(file);
}