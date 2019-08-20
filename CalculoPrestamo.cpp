//
// Created by Maikol Guzman  on 2019-08-08.
//
#include <iostream>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo() {}

CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto) {}

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT) {
	float porcentaje = 0;
	int buscarPorcentaje = porcentajeTXT.find("%"); // Busca que el valor traiga un % al final. Ejemplo 2%
	
	if (buscarPorcentaje > 0) {
		porcentaje = std::stof(porcentajeTXT.substr(0, buscarPorcentaje));
		if (porcentaje > 0) {
			porcentaje = porcentaje / 100;
		}
	}
	return porcentaje;
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
	int meses = 0;
	int ano = 0;
	int buscarTiempoAno = tiempoTXT.find("A"); // Busca que el valor traiga una A al final. Ejemplo 1A = 1 año
	int buscarTiempoMes = tiempoTXT.find("M"); // Busca que el valor traiga una M al final. Ejemplo 6M = 6 meses
	
	if (buscarTiempoAno > 0) {
		ano = stoi(tiempoTXT.substr(0, buscarTiempoAno));
		if (ano > 0) {
			meses = ano * 12;
		}
	} else if (buscarTiempoMes > 0 ) {
		meses = stoi(tiempoTXT.substr(0, buscarTiempoMes));
	}
	
	return meses ;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
	float tasaMensual = tasaAnual / 12;
	float interes = tasaMensual * balance;
	return interes;
}


std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT) {
	std::string reporte = "";
	int meses = calcularTiempoEnMeses(tiempoTXT) + 1;
	float porcentaje = obtenerPorcentaje(porcentajeTXT);
	float balance = getMonto();
	float balanceNuevo = getMonto();
	
	for (int mes = 1; mes < meses; ++mes) {
		float interesMensual = calcularInteresMensual(balanceNuevo, porcentaje);
		balance = balanceNuevo;
		balanceNuevo = balance + interesMensual;
		
		reporte = reporte + "Tasa [" + porcentajeTXT + "], Mes [" + std::to_string(mes) + "], balance inicial [" + std::to_string(balance) +
			"], interes [" + std::to_string(interesMensual) + "], balance nuevo [" +
			std::to_string(balanceNuevo) + "] \n";
	}
	
	return reporte;
}

float CalculoPrestamo::getMonto() const {
	return monto;
}

void CalculoPrestamo::setMonto(float monto) {
	CalculoPrestamo::monto = monto;
}
