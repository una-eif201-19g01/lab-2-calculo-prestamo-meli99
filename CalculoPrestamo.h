//
// Created by Maikol Guzman  on 2019-08-08.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>
class CalculoPrestamo{
    float monto;
    CalculoPrestamo();
    CalculoPrestamo(int64_t monto);
    void setMonto(float monto);
    float getMonto();
    float obtenerPorcentaje(std::string porcentajeTXT);
    int calcularTiempoEnMeses(std::string tiempoTXT);
    float calcularInteresMensual(float balance, float tasaAnual);
    reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);
};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
