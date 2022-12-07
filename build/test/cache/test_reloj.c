#include "inc/reloj.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






reloj_t reloj;





void simular_segundos(int segundos){

        for(int index=0; index < segundos * 5; index++) {

        NuevoTickReloj(reloj);

    }

}







void setUp (void){

    static const uint8_t INICIAL[] = {1, 2, 3, 4};

    reloj = CrearReloj(5);

    ConfigurarReloj(reloj, INICIAL, sizeof(INICIAL));



}





void test_hora_inicial(void){

    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];

    uint8_t alarma[4];

    reloj_t reloj = CrearReloj(5);



    do {if (!(TraerHoraReloj(reloj, hora, sizeof(hora)))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(31)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

    do {if (!(ObtenerAlarmaReloj(reloj,alarma,sizeof(alarma)))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(33)));}} while(0);

}





void test_configurar_hora_actual (void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};

    uint8_t hora[6];

    do {if ((TraerHoraReloj(reloj, hora, sizeof(hora)))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_pasa_un_segundo(void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 1};

    uint8_t hora[6];



    simular_segundos(1);

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_pasan_diez_segundos(void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 1, 0};

    uint8_t hora[6];



    simular_segundos(10);

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}







void test_pasa_un_minuto(void){

    static const uint8_t ESPERADO[] = {1, 2, 3, 5, 0, 0};

    uint8_t hora[6];



    simular_segundos(60);

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_pasan_diez_minutos(void){

    static const uint8_t ESPERADO[] = {1, 2, 4, 4, 0, 0};

    uint8_t hora[6];



    simular_segundos(10*60);

    TraerHoraReloj(reloj, hora, sizeof(hora));

    UnityAssertEqualIntArray(( const void*)((ESPERADO)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ESPERADO))), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_configurar_y_obtener_alarma (void){

    static const uint8_t ALARMA[] = {1, 2, 3, 5};

    uint8_t hora[4];



    ConfigurarAlarmaReloj(reloj, ALARMA, sizeof(ALARMA));

    do {if ((ObtenerAlarmaReloj(reloj, hora, sizeof(ALARMA)))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ALARMA)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ALARMA))), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}





void test_configurar_y_deshabilitar_alarma (void){

    static const uint8_t ALARMA[] = {1, 2, 3, 5};

    uint8_t hora[4];



    ConfigurarAlarmaReloj(reloj, ALARMA, sizeof(ALARMA));

    do {if (!(CambiarAlarmaReloj(reloj))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(101)));}} while(0);



    do {if (!(ObtenerAlarmaReloj(reloj, hora, sizeof(hora)))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(103)));}} while(0);

    UnityAssertEqualIntArray(( const void*)((ALARMA)), ( const void*)((hora)), (UNITY_UINT32)((sizeof(ALARMA))), (

   ((void *)0)

   ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
