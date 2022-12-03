#include "unity.h"
#include "reloj.h"

#define TICKS_POR_SEGUNDO 5

reloj_t reloj;


void simular_segundos(int segundos){
        for(int index=0; index < segundos * TICKS_POR_SEGUNDO; index++) {
        NuevoTickReloj(reloj);
    }
}


//Creo el reloj y lo pongo en hora
void setUp (void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    reloj = CrearReloj(TICKS_POR_SEGUNDO);//inicializo el reloj
    ConfigurarReloj(reloj, INICIAL, sizeof(INICIAL));

}

//Configurar libreria, consultar hora, y la hora debe ser invalida
void test_hora_inicial(void){
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};
    uint8_t hora[6];
    reloj_t reloj = CrearReloj(TICKS_POR_SEGUNDO);
    
    TEST_ASSERT_FALSE(TraerHoraReloj(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}

//Configurar libreria, ajustar hora (con valores correctos), consultar hora y la hora tiene que ser valida
void test_configurar_hora_actual (void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6];
    TEST_ASSERT_TRUE(TraerHoraReloj(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}

//Simular el paso de n ciclos de reloj, consultar la hora y verificar que avanza un segundo
void test_pasa_un_segundo(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 1};
    uint8_t hora[6];
    
    simular_segundos(1);
    TraerHoraReloj(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}

//Simular el paso de 10*n ciclos de reloj, consultar la hora y verificar que avanza un segundo
void test_pasan_diez_segundos(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 1, 0};
    uint8_t hora[6];
    
    simular_segundos(10);
    TraerHoraReloj(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}


//Simular el paso de un minuto de reloj, consultar la hora y verificar que avanza un minuto
void test_pasa_un_minuto(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 5, 0, 0};
    uint8_t hora[6];
    
    simular_segundos(60);
    TraerHoraReloj(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}

//Simular el paso de 10 minutos de reloj, consultar la hora y verificar que avanza un minuto
void test_pasan_diez_minutos(void){
    static const uint8_t ESPERADO[] = {1, 2, 4, 4, 0, 0};
    uint8_t hora[6];
    
    simular_segundos(10*60);//simulate minutos
    TraerHoraReloj(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY (ESPERADO, hora, sizeof(ESPERADO));
}

//6-SIMULAR LA ALARMA 

void test_configurar_y_obtener_alarma (void){
    static const uint8_t ALARMA[] = {1, 2, 3, 5};
    uint8_t hora[4];

    ConfigurarAlarmaReloj(reloj, ALARMA, sizeof(ALARMA));
    TEST_ASSERT_TRUE(ObtenerAlarmaReloj(reloj, hora, sizeof(ALARMA)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ALARMA, hora, sizeof(ALARMA));
}