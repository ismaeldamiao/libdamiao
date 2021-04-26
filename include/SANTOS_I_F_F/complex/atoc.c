/* *****************************************************************************
   Programa para converter uma string em um numero complexo.
   Metodo: Guarda os valores separados por sinal (+ -) em uma string
   auxiliar, alem de separar a parte imaginaria da real identificando
   a unidade imaginaria, o que permite usar a parte imaginaria antes da real
   e vice-versa.
   *****************************************************************************
   E-mail: ismaellxd@gmail.com
   Site: https://ismaeldamiao.github.io/
   *****************************************************************************
   Copyright (C) SANTOS, I.F.F. (Ismael Damiao)

   Permission is hereby granted, free of charge, to any person obtaining a copy 
   of this software and associated documentation files (the “Software”), to 
   deal in the Software without restriction, including without limitation the 
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
   sell copies of the Software, and to permit persons to whom the Software is 
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in 
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
   IN THE SOFTWARE.
***************************************************************************** */
#include <stdlib.h>
#include <complex.h>

#define str_size 512
_Complex double atoc(const char *str){
   int i, j, i_imag;
   double real = 0.0, imag;
   char str_aux[3][str_size];

   /* ***
      Limpar as string auxiliares
   *** */
   for(i = 0; i < 3; ++i)
   for(j = 0; j < (str_size-1); ++j)
   str_aux[i][j] = ' ';

   /* ***
      Guardar os valores nas string auxiliares
   *** */
   j = 0; /* Guarda o valor da parte (real/imaginaria) a ser escrita */
   i_imag = -1; /* Lembra qual o valor da parte imaginaria, se existir */
   for(i = 0;; ++i){
      if(str[i] == '\0') break; /* Caso seja o fim da string */
      else if((str[i] == '+') || (str[i] == '-')) ++j; /* Caso mude de parte */
      else if((str[i] == 'i') || (str[i] == 'I')) i_imag = j;
      str_aux[j][i] = str[i];
   }
   /* ***
      Converter a parte real para double
   *** */
   for(i = 0; i < 3; ++i){
      if(i != i_imag){
         real = atof(str_aux[i]);
         if(real != 0.0) break;
      }
   }
   /* ***
      Converter a parte imaginaria para double
   *** */
   if(i_imag == -1){
      imag = 0.0; /* Numero puramente real */
   }else{
      imag = atof(str_aux[i_imag]);
      /* 'i' sozinho da '0.0' mas o '1.0' fica implicito */
      if(imag == 0.0) imag = 1.0;
   }
   return (real + imag*_Complex_I);
}
#undef str_size