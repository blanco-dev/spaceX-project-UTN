#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20


const char* paises[] =
{
    "Afganistan",
    "Albania",
    "Alemania",
    "Andorra",
    "Angola",
    "Antigua y Barbuda",
    "Arabia Saudita",
    "Argelia",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaiyan",
    "Bahamas",
    "Banglades",
    "Barbados",
    "Barein",
    "Belgica",
    "Belice",
    "Benin",
    "Bielorrusia",
    "Birmania",
    "Bolivia",
    "Bosnia",
    "Botsuana",
    "Brasil",
    "Brunei",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Butan",
    "Cabo Verde",
    "Camboya",
    "Camerun",
    "Canada",
    "Catar",
    "Chad",
    "Chile",
    "China",
    "Chipre",
    "Vaticano",
    "Colombia",
    "Comoras",
    "Corea del Norte",
    "Corea del Sur",
    "Costa de Marfil",
    "Costa Rica",
    "Croacia",
    "Cuba",
    "Dinamarca",
    "Dominica",
    "Ecuador",
    "Egipto",
    "El Salvador",
    "Emiratos Arabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "Espa�a",
    "Estados Unidos",
    "Estonia",
    "Eswatini",
    "Etiopia",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gabon",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea-Bisau",
    "Guinea Ecuatorial",
    "Guyana",
    "Haiti",
    "Honduras",
    "Hungria",
    "India",
    "Indonesia",
    "Irak",
    "Iran",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salomon",
    "Israel",
    "Italia",
    "Jamaica",
    "Japon",
    "Jordania",
    "Kazajistan",
    "Kenia",
    "Kirguistan",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "Libano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Mali",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "M�xico",
    "Micronesia",
    "Moldavia",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Oman",
    "Paises Bajos",
    "Pakistan",
    "Palaos",
    "Panama",
    "Papua Nueva Guinea",
    "Paraguay",
    "Peru",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "Republica Centroafricana",
    "Republica Checa",
    "Republica Democr�tica del Congo",
    "Republica Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Cristobal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Lucia",
    "Santo Tome y Pr�ncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sudafrica",
    "Sudan",
    "Sudan del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikistan",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "Tunez",
    "Turkmenistan",
    "Turquia",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Yibuti",
    "Zambia",
    "Zimbabue"
};

void limpiarPantalla()
{
    system("cls");
}


stAstronauta crearUnAstro(char astronauta[])
{
    stAstronauta aux;

    //para no tener que cambiar la id el usuario incia el programa ya con UN astronauta predeterminado

    ///datos por defecto para crear un astro
    int ultimaID = encontrarUltimaID(astronauta) + 1;
    aux.id =ultimaID; // arranca en 10 , de 10 para abajo son los predeterminados y luego de 10 para arriba los del usuario
    aux.horasDeVuelo = 0;
    aux.cantMisionesRealizadas = 0;
    aux.horasEnEEI = 0;
    aux.estado = 1;// 1 activo, 2 retirado

    /// Validacion del astronauta
    puts("-----------------------DATOS DEL ASTRONAUTA-----------------------");
    do
    {
        printf("Ingrese el nombre del astronauta: \n");
        fflush(stdin);
        gets(aux.nombre);
    }
    while(validarString(aux.nombre)==0);

    do
    {
        printf("Ingrese el apellido del astronauta: \n");
        fflush(stdin);
        gets(aux.apellido);
    }
    while(validarString(aux.apellido)==0);

    do
    {
        printf("Ingrese el apodo del astronauta: \n");
        fflush(stdin);
        gets(aux.apodo);
    }
    while(validarString(aux.apodo)==0);

    do
    {
        printf("Ingrese la edad del astronauta: \n");
        fflush(stdin);
        scanf("%i",&aux.edad);
    }
    while(validarEdad(aux.edad)==0);
    do
    {
        printf("Ingrese el pais el astronauta: \n");
        fflush(stdin);
        scanf("%s",&aux.nacionalidad);
    }
    while(validarNacionalidad(aux.nacionalidad)==0);

    validarEspecialidad(aux.especialidad);
    // como ya cargo todo el astronauta se incrementan las id para que se pueda cargar el siguiente astro con su nueva id


    return aux;
}

int validarString(char auxNombre[])
{
    if (strlen(auxNombre) > 20 || strlen(auxNombre) < 3)
    {
        printf("Ingrese una palabra entre 3 y 20 letras\n\n");
        return 0;
    }
    else
    {
        return 1;
    }


}

int validarEdad(int edad)
{

    if (edad < 18  || edad > 60)
    {
        printf("Ingrese una edad mayor a 18 y menor a 60 anios\n\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

int validarNacionalidad(char nacionalidad[])
{
    int i = 0;

    while(i<192)
    {
        if(strcmpi(nacionalidad,paises[i])== 0)
        {
            return 1;
        }
        i++;
    }
    printf("|Error|ingrese un pais existente\n\n");
    return 0;
}

void validarEspecialidad(char especialidad[])
{

    int flag = 0;
    int op = 0;

    do
    {
        puts("------------------INGRESE UNA OPCION--------------------\n");
        mostrarEspecialidad();
        scanf("%i",&op);
        limpiarPantalla();
        switch(op)
        {
        case 1:
            strcpy(especialidad,"Piloto");
            flag = 1;
            break;
        case 2:
            strcpy(especialidad,"Astrofisico");
            flag = 1;
            break;
        case 3:
            strcpy(especialidad,"Ingeniero Espacial");
            flag = 1;
            break;
        case 4:
            strcpy(especialidad,"Biologo");
            flag = 1;
            break;
        case 5:
            strcpy(especialidad,"Programador espacial");///NO PONER MAS DE 3 PALABRAS PORQUE SE ROMPEN LAS HORAS ACUMULADAS
            flag = 1;
            break;
        default:
            limpiarPantalla();
            printf("OPCION INCORRECTA...Reintente\n");
            break;
        }
    }
    while(flag == 0);

}
void mostrarEspecialidad()
{

    printf("1-Piloto\n");
    printf("2-Astrofisico\n");
    printf("3-Ingeniero Espacial\n");
    printf("4-Biologo\n");
    printf("5-Programador espacial\n");

}
int encontrarUltimaID(char astronauta[])
{

    int ultimaID;
    stAstronauta astroAux;
    FILE* aux;
    aux = fopen(astronauta,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stAstronauta)*-1,SEEK_END);
        fread(&astroAux,sizeof(stAstronauta),1,aux);
        ultimaID = astroAux.id;
        fclose(aux);
    }
    return ultimaID;
}
///CARGA DEL ARCHIVO

void cargarUnAstroToArchivo(char archivoAstronautas[])
{

    FILE* archi;
    stAstronauta aux;
    archi = fopen(archivoAstronautas,"ab");
    if(archi != NULL)
    {
        aux = crearUnAstro(archivoAstronautas);
        fwrite(&aux,sizeof(stAstronauta),1,archi);
        fclose(archi);
    }
    else
    {
        printf("error con el archivo");
    }
}

void mostrarAstronautas(char archivoAstronautas[])
{

    FILE* astro = fopen(archivoAstronautas,"rb");
    stAstronauta aux;

    if(astro != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,astro)>0)
        {
            mostrarUnAstronauta(aux);
        }
        fclose(astro);
    }
    else
    {
        printf("Error con el archivo");
    }
}

void mostrarUnAstronauta(stAstronauta aux)
{

    puts("\n--------------------------------------------------------------------------\n");
    printf("ID............................: |%i| \n",aux.id);
    printf("Nombre........................: |%s| \n",aux.nombre);
    printf("Apellido......................: |%s| \n",aux.apellido);
    printf("Apodo.........................: |%s| \n",aux.apodo);
    printf("Edad..........................: |%i| \n",aux.edad);
    printf("Nacionalidad..................: |%s| \n",aux.nacionalidad);
    printf("Especialidad..................: |%s| \n",aux.especialidad);
    printf("Horas de vuelo acumulado......: |%i| \n",aux.horasDeVuelo);
    printf("Misiones espaciales realizadas: |%i| \n",aux.cantMisionesRealizadas);
    printf("Horas en la EEI...............: |%i| \n",aux.horasEnEEI);
    printf("Estado........................: |%i| \n",aux.estado);
    puts("\n");

}
///MODIFICAR ASTRONAUTA

int validarIDastro(int dato,char archivo[])
{
    stAstronauta aux;
    FILE * archi=fopen(archivo,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,archi)>0)
        {
            if (dato == aux.id)
            {
                return 1;
            }
        }


        printf("Ingrese un ID de astronauta valido");
        return 0;


        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }
}

void cargarAstroModificado(char archivoAstronauta[])
{

    stAstronauta astro;


    FILE* archi= fopen(archivoAstronauta,"r+b");

    int datoID = 0;
    int posAstro = 0;

    if(archi != NULL)
    {

        limpiarPantalla();
        mostrarAstronautas(archivoAstronauta);

        puts("----------------------INGRESE LA ID DEL ASTRONAUTA A MODIFICAR----------------------\n");

        do
        {
            printf("Ingrese aqui: \n");
            datoID = preguntarDato();

        }
        while(validarIDastro(datoID,archivoAstronauta)== 0);

        posAstro = encontrarPosicionAstroXID(archivoAstronauta,datoID);   // devuelvo la posicion en la que esta el astronauta con el ID buscado

        fseek(archi,sizeof(stAstronauta)*posAstro,SEEK_SET);            // muevo el indicador de posicion a donde se encuentra el astronauta con el ID buscado y le resto 1 para leerlo
        fread(&astro,sizeof(stAstronauta),1,archi);                    // lo leo, se que me va a leer el astronauta que quiero ya que me movi una posicion atras

                                                                        // le paso la direccion de memoria del astronauta que acabo de leer y el indicador de pos va a aumentar por el read
        modificarUnAstro(&astro);
        fseek(archi,sizeof(stAstronauta)*-1,SEEK_CUR);               // por culpa del read debo moverme una posicion hacia atras para poder sobreescribir el astronauta modificado
        fwrite(&astro,sizeof(stAstronauta),1,archi);                // escribo el astronauta modificado

        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }

}

int contarRegistros(char archivo[])
{
    int cant=0;
    FILE*archi=fopen(archivo,"rb");

    if(archi != NULL)
    {
        fseek(archi,sizeof(stAstronauta) -1,SEEK_END);
        cant= ftell(archi) / sizeof(stAstronauta);
        fclose(archi);
    }
    else
    {
        printf("Error con archivo");
    }

    return cant;
}


int preguntarDato()
{
    int dato= 0;
    printf("Ingrese un dato: \n");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}


int encontrarPosicionAstroXID(char archivoAstronautas[],int datoID)
{
    int posAstro=0;
    int  flag=0;
    stAstronauta aux;

    FILE * archi=fopen(archivoAstronautas,"rb");

    if(archi != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,archi)>0 && (flag == 0))
        {
            if(aux.id == datoID)
            {
                posAstro= ftell(archi) / sizeof(stAstronauta);
                flag=1;
            }
        }

        fclose(archi);
    }
    else
    {
        printf("Error con el archivo");
    }


    return posAstro;

}



void modificarUnAstro(stAstronauta* astro)
{

    int opsw = 0;
    limpiarPantalla();

    puts("-----------ASTRONAUTA ELEGIDO-------\n");
    mostrarUnAstronauta(*astro);

    printf("Que desea cambiar\n");
    printf("1-Modificar Nombre\n");
    printf("2-Modificar apellido\n");
    printf("3-Modificar apodo\n");
    printf("4-Modificar edad\n");
    printf("5-Modificar estado\n");
    // Modificar todo el astronauta
    printf("6-No realizar ninguna modificacion\n");

    puts("Elija una opcion: \n");
    scanf("%i",&opsw);

    switch(opsw)
    {
    case 1:
        printf("Ingrese el nuevo nombre\n");
        fflush(stdin);
        gets(astro->nombre);
        break;
    case 2:
        printf("ingrese el nuevo apellido\n");
        fflush(stdin);
        gets(astro->apellido);
        break;
    case 3:
        printf("Ingrese el nuevo apodo\n");
        fflush(stdin);
        gets(astro->apodo);
        break;
    case 4:
        printf("Ingrese la nueva edad\n");
        fflush(stdin);
        scanf("%i",&astro->edad);
        break;
    case 5:
        printf("Ingrese el nuevo estado\n");
        fflush(stdin);
        scanf("%i",&astro->estado);
        break;
    case 6:
        opsw == -1;
        break;
    default:
        printf("Opcion no valida, reintente...\n");
        break;
    }

    puts("-----------Astronauta modificado-------\n");
    mostrarUnAstronauta(*astro);


}

