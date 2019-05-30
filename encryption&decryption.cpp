#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))




unsigned int k[64] = {
	1116352408,1899447441,3049323471,3921009573,961987163,1508970993,2453635748,2870763221,
	3624381080,310598401,607225278,1426881987,1925078388,2162078206,2614888103,3248222580,
	3835390401,4022224774,264347078,604807628,770255983,1249150122,1555081692,1996064986,
	2554220882,2821834349,2952996808,3210313671,3336571891,3584528711,113926993,338241895,
	666307205,773529912,1294757372,1396182291,1695183700,1986661051,2177026350,2456956037,
	2730485921,2820302411,3259730800,3345764771,3516065817,3600352804,4094571909,275423344,
	430227734,506948616,659060556,883997877,958139571,1322822218,1537002063,1747873779,
	1955562222,2024104815,2227730452,2361852424,2428436474,2756734187,3204031479,3329325298
};

/*uint32_t k[64];
		//unsigned long long int k[64];
			k[0] = 0x428a2f98;
			k[1] = 0x71374491;
			k[2] = 0xb5c0fbcf;
			k[3] = 0xe9b5dba5;
			k[4] = 0x3956c25b;
			k[5] = 0x59f111f1;
			k[6] = 0x923f82a4;
			k[7] = 0xab1c5ed5;
			k[8] = 0xd807aa98;
			k[9] = 0x12835b01;
			k[10] = 0x243185be;
			k[11] = 0x550c7dc3;
			k[12] = 0x72be5d74;
			k[13] = 0x80deb1fe;
			k[14] = 0x9bdc06a7;
			k[15] = 0xc19bf174;
			k[16] = 0xe49b69c1;
			k[17] = 0xefbe4786;
			k[18] = 0x0fc19dc6;
			k[19] = 0x240ca1cc;
			k[20] = 0x2de92c6f;
			k[21] = 0x4a7484aa;
			k[22] = 0x5cb0a9dc;
			k[23] = 0x76f988da;
			k[24] = 0x983e5152;
			k[25] = 0xa831c66d;
			k[26] = 0xb00327c8;
			k[27] = 0xbf597fc7;
			k[28] = 0xc6e00bf3;
			k[29] = 0xd5a79147;
			k[30] = 0x06ca6351;
			k[31] = 0x14292967;
			k[32] = 0x27b70a85;
			k[33] = 0x2e1b2138;
			k[34] = 0x4d2c6dfc;
			k[35] = 0x53380d13;
			k[36] = 0x650a7354;
			k[37] = 0x766a0abb;
			k[38] = 0x81c2c92e;
			k[39] = 0x92722c85;
			k[40] = 0xa2bfe8a1;
			k[41] = 0xa81a664b;
			k[42] = 0xc24b8b70;
			k[43] = 0xc76c51a3;
			k[44] = 0xd192e819;
			k[45] = 0xd6990624;
			k[46] = 0xf40e3585;
			k[47] = 0x106aa070;
			k[48] = 0x19a4c116;
			k[49] = 0x1e376c08;
			k[50] = 0x2748774c;
			k[51] = 0x34b0bcb5;
			k[52] = 0x391c0cb3;
			k[53] = 0x4ed8aa4a;
			k[54] = 0x5b9cca4f;
			k[55] = 0x682e6ff3;
			k[56] = 0x748f82ee;
			k[57] = 0x78a5636f;
			k[58] = 0x84c87814;
			k[59] = 0x8cc70208;
			k[60] = 0x90befffa;
			k[61] = 0xa4506ceb;
			k[62] = 0xbef9a3f7;
			k[63] = 0xc67178f2;
*/



void SHA1(unsigned char * str1, int x)
{
	int i, j;
unsigned  int h0,h1,h2,h3,h4,h5,h6,h7,a,b,c,d,e,f,g,h,t1,t2,temp;
h0 = 1779033703;
h1 = 3144134277;
h2 = 1013904242;
h3 = 2773480762;
h4 = 1359893119;
h5 = 2600822924;
h6 = 528734635;
h7 = 1541459225;





printf("string is: %s\n",str1);

unsigned char str[x+100];
for(i=0; i< x+100; i++)
	str[i]=str1[1];

int current_length = x+100;
int n=current_length;
 j=0;
int val[n];
for( i = 0; i < n; i++)
    {
      val[i] = (int)(str[i]);
    }

    for( i = 0; i < n; i++)
        {
              printf("%d ",val[i]);
        }
printf("\n");


    int message[n*8];

      for( i = 0; i<n; i++)
         {
           int s=8;
           int s1=val[i];
           int bin[8]={0,0,0,0,0,0,0,0};
             while (s1 > 0)
           {
            bin[s-1] = s1 % 2;
            s1 /= 2;
            s=s-1;
           }
        for( i=0;i<8;i++)
        {
        message[j]=bin[i];
        j=j+1;
        }
      }


      printf("message is:\n");
      for( i = 0; i<n*8; i++)
          {
                printf("%d",message[i]);
          }


 int len=n*8;
 int extbits=(len+65)%512;
 int totalbits=len+65+512-extbits;

 printf("\ntotalbits before padding are %d\n",len);

 int message_paddded[totalbits];
 int t;
 for(t=0; t<len; t++)
 message_paddded[t]=message[t];




 message_paddded[t]=1;
 t++;

 for(;t<(totalbits-64); t++)
 message_paddded[t]=0;

 int n1=len;
 int binaryNum[64];

    for( i=0; i<64; i++)
    binaryNum[i]=0;


    int j1=63;
    while (n1 > 0) {

        binaryNum[j1] = n1% 2;
        n1 = n1 / 2;
        j1=j1-1;
    }
    int k1=0;
    for (; t<totalbits; t++)
        message_paddded[t]=binaryNum[k1++];

    printf("\nPadded message is\n");
    for ( i=0; i<totalbits; i++)
        printf("%d",message_paddded[i]);


				printf("\ntotalbits after padding are %d\n",totalbits);

        int M[totalbits/4];
        int newl=0;
        for( i=0;i<totalbits;i=i+4)
        {

          M[i/4]=message_paddded[i]*8+message_paddded[i+1]*4+message_paddded[i+2]*2+message_paddded[i+3]*1;
        }

        printf("\nhexadecimal message M is\n");
        for ( i=0; i<totalbits/4; i++)
            printf("%d",M[i]);

            printf("\n");


            unsigned int word[64];
						int number_of_chunks = totalbits/512;
						for( i=0;i<number_of_chunks;i++)
		        {
						for(j=0;j<16;j++)
		        {
		              char str[33];
		              int s=0;
		              int c;
		              for( c=j*32;c<=(j+1)*32-1;c++)
		              {
		                 str[s++]=message_paddded[c]+'0';

		              }
		              str[32]='\0';

		              int p=0;
		              int sum=0;
		              for( i=31;i>=0;i--)
		              {
		            	  int pa=1;
		            	  int y;
		            	  for(y=0; y<i; y++)
		            		  pa=pa*2;
		            	  sum = sum + (pa * (str[p] - '0'));
		                  p++;
		              }

		              word[j]=sum;




		        }

            for (  i=16; i < 64;i++)
		          word[i] = SIG1(word[i - 2]) + word[i - 7] + SIG0(word[i - 15]) + word[i - 16];



            for ( i=0;i<64;i++)
            printf("word[%d] is %d\n",i,word[i]);


						a=h0;
						b=h1;
						c=h2;
						d=h3;
						e=h4;
						f=h5;
						g=h6;
						h=h7;

            for ( i = 0; i < 64; ++i)
             {
		                  t1 = h + EP1(e) + CH(e,f,g) + k[i] + word[i];
		                  t2 = EP0(a) + MAJ(a,b,c);
		                  h = g;
		                  g = f;
		                  f = e;
		                  e = d + t1;
		                  d = c;
		                  c = b;
		                  b = a;
		                  a = t1 + t2;
	           }

             h0 = h0 + a;
             h1 = h1 + b;
             h2 = h2 + c;
             h3 = h3 + d;
             h4 = h4 + e;
             h5 = h5 + f;
             h6 = h6 + g;
             h7 = h7 + h;




}
printf("256 Hash is: %x%x%x%x%x%x%x%x",h0, h1, h2, h3, h4,h5,h6,h7);
printf("\n");


unsigned int a0,a1,a2,a3;
a0=h0^h7;
a1=h1^h6;
a2=h2^h5;
a3=h3^h4;

printf("128 Hash is: %x%x%x%x",a0,a1,a2,a3);
printf("\n");

//LFSR
int seed[7]={0,0,0,0,0,0,1};
int tap[3]={0,1,6};
int co[128][7];
int B[128];
int no=sizeof(seed)/sizeof(seed[0]);
int mo=sizeof(tap)/sizeof(tap[0]);
int bo[mo-1];

for( i=0;i<7;i++)
co[0][i]=seed[i];

int vish=seed[0]^seed[1]^seed[6];
printf("exor %d\n",vish);
int k2;
for( k2=0;k2<=pow(2,no)-1;k2++)
{

      bo[0]=seed[tap[0]]^seed[tap[1]];
			if(mo>2)
				{
					for( i=0;i<=mo-3;i++)
					 bo[i+1]=seed[tap[i+2]]^bo[i];

				 }

				 for( j=0;j<=no-2;j++)
				 {
					 seed[no-j-1]=seed[no-j-2];

				 }
				 seed[0]=bo[mo-2];
				 int s;
				 for( s=0;s<7;s++)
					 co[k2+1][s]=seed[s];

}

for( i=0;i<128;i++)
{
	for( j=0;j<7;j++)
		{
			printf("%d ",co[i][j]);
		}
		printf("\n");
}

//binary to decimal conversion
for( i=0;i<128;i++)
{
	int sum=0;
	int v=6;
	for( j=0;j<7;j++)
	{
		sum=sum+co[i][j]*pow(2,v-j);
	}
	B[i]=sum;
}

printf("\n Array of random num is\n");
for( i=0;i<128;i++)
{
	printf("%d ",B[i]);
}

int index[128];
for( i=0;i<128;i++)
{
	index[i]=(B[i]%128);
}

printf("\n Array of random index is\n");
for( i=0;i<128;i++)
{
	printf("%d ",index[i]);
}

int final_hash[128];
//decimal to binary conversion of a0,a1,a2,a3
unsigned int value1=a0;
int binary1[32];
unsigned int value2=a1;
int binary2[32];
unsigned int value3=a2;
int binary3[32];
unsigned int value4=a3;
int binary4[32];
int con=0;
int i1 = 0;
    while (value1 > 0)
		{

        binary1[i1] = value1 % 2;

        value1 = value1 / 2;
        i1++;
    }

		printf("\nbinary1 is:\n");
		for( i=0;i<32;i++)
		{
			printf("%d",binary1[i]);
    }

			int i2 = 0;
			    while (value2 > 0)
					{

			        binary2[i2] = value2 % 2;

			        value2 = value2 / 2;
			        i2++;
			    }

					printf("\nbinary2 is:\n");
					for(i=0;i<32;i++)
					{
						printf("%d",binary2[i]);
					}


					int i3 = 0;
					    while (value3 > 0)
							{

					        binary3[i3] = value3 % 2;

					        value3 = value3 / 2;
					        i3++;
					    }

							printf("\nbinary3 is:\n");
							for( i=0;i<32;i++)
							{
								printf("%d",binary3[i]);
							}

							int i4 = 0;
							    while (value4 > 0)
									{

							        binary4[i4] = value4 % 2;

							        value4 = value4 / 2;
							        i4++;
							    }

									printf("\nbinary4 is:\n");
									for( i=0;i<32;i++)
									{
										printf("%d",binary4[i]);
									}

									for( i=0;i<32;i++)
									{
										final_hash[con]=binary1[i];
										con=con+1;
									}

									for( i=0;i<32;i++)
									{
										final_hash[con]=binary2[i];
										con=con+1;
									}

									for( i=0;i<32;i++)
									{
										final_hash[con]=binary3[i];
										con=con+1;
									}

									for( i=0;i<32;i++)
									{
										final_hash[con]=binary4[i];
										con=con+1;
									}

									printf("\nfinal_hash is:\n");
									for( i=0;i<128;i++)
									{
										printf("%d",final_hash[i]);
									}

									//swapping using LFSR
									for( i=0;i<128;i++)
									{
										int temp5=final_hash[i];
										final_hash[i]=final_hash[B[i]];
										final_hash[B[i]]=temp5;
									}

									printf("\nfinal_hash after swapping is:\n");
									for( i=0;i<128;i++)
									{
										printf("%d",final_hash[i]);
									}

                  int con1=0;
									int binary11[32],binary21[32],binary31[32],binary41[32];
									for( i=0;i<32;i++)
									{
										binary11[i]=final_hash[con1];
										con1=con1+1;
									}

									for( i=0;i<32;i++)
									{
										binary21[i]=final_hash[con1];
										con1=con1+1;
									}

									for( i=0;i<32;i++)
									{
										binary31[i]=final_hash[con1];
										con1=con1+1;
									}

									for( i=0;i<32;i++)
									{
										binary41[i]=final_hash[con1];
										con1=con1+1;
									}


									unsigned int u0=0;
									unsigned int u1=0;
									unsigned int u2=0;
									unsigned int u3=0;

									for( i=0;i<32;i++)
									{
										u0=u0+binary11[i]*pow(2,31-i);
									}

									for( i=0;i<32;i++)
									{
										u1=u1+binary21[i]*pow(2,31-i);
									}

									for( i=0;i<32;i++)
									{
										u2=u2+binary31[i]*pow(2,31-i);
									}

									for( i=0;i<32;i++)
									{
										u3=u3+binary31[i]*pow(2,31-i);
									}


									printf("\n128 Hash after swapping is: %x%x%x%x",u0,u1,u2,u3);
									printf("\n");


}



int main()
{
//SHA1((unsigned char *)"The quick brown fox jumps over the lazy dog", 43);
SHA1((unsigned char *)"abc", 3);
return 0;
}
