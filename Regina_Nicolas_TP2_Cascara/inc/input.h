/**
* \brief Valida si el valor enviado por parametro es un numero
* \param numero cadena de caracteres que quiere validarse si es un numero
* \return Si es un numero devuelve 1, sino 0
*/
int validaInt(char numero[]);

/**
* \brief Valida si el valor enviado por parametro es un numero flotante
* \param numero cadena de caracteres que quiere validarse si es un numero
* \return Si es un numero devuelve 1, sino 0
*/
int validaFloat(char numero[]);

/**
* \brief Valida si el valor enviado por parametro es una letra
* \param numero cadena de caracteres que quiere validarse si es una letra
* \return Si es una letra devuelve 1, sino 0
*/
int validaLetra(char caracter[]);

/**
* \brief Solicita un n�mero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un n�mero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud m�nima de la cadena
* \param hiLimit Longitud m�xima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

