#include "inc/reloj.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






reloj_t reloj;





void setUp (void){

    static const uint8_t INICIAL[] = {1, 2, 3, 4};

    reloj = CrearReloj(5);

    ConfigurarReloj(reloj, INICIAL, sizeof(INICIAL));



}





void test_hora_inicial(void){

    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    reloj_t reloj = CrearReloj(5);



    do {if (!(TraerHoraReloj(reloj, hora, sizeof(hora)))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(22)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_configurar_hora_actual (void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t hora[6];

    do {if ((TraerHoraReloj(reloj, hora, sizeof(hora)))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_pasa_un_segundo(void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 1};

    uint8_t hora[6];



    for(int index=0; index < 5; index++) {

        NuevoTickReloj(reloj);

    }

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_pasan_diez_segundos(void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 1, 0};

    uint8_t hora[6];



    for(int index=0; index < 10 * 5; index++) {

        NuevoTickReloj(reloj);

    }

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
