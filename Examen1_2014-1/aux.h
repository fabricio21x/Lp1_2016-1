#ifndef AUX_H
#define AUX_H

void *colocarDatos(char *codCurso, char *nomCurso, double credCurso);
void *colocarDatos(int codAlumno, char *nomAlumno, int especialidad);
int buscarAlumno(void **arrAlumnos, int codAlumno);
void agregarNotaCurso(void *&alumno,char *codCurso,int nota);


#endif /* AUX_H */

