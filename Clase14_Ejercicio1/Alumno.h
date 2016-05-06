/* 
 * File:   Alumno.h
 * Author: fernandoalva
 *
 * Created on April 27, 2016, 9:28 AM
 */

#ifndef ALUMNO_H
#define	ALUMNO_H

void leerAlumnos(void *&alumnos, int codAlumno);
void imprimirAlumnos(void *alumnos);
int buscarAlumno(void **arrAlumnos, int codAlumno);
void agregarNotaCurso(void *&alumno, char *codCurso, int nota);
void imprimirAlumnosNotas(void *lstAlumnos);

#endif	/* ALUMNO_H */

