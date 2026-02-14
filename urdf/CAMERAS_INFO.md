# Documentación de Cámaras del Rover Perseverance (m2020.urdf)

Este archivo detalla los enlaces (Links/Frames) definidos en el archivo `m2020.urdf` que corresponden a los sensores de visión (cámaras) del rover, junto con su función y ubicación en la misión real.

## 1. Cámaras de Ingeniería (Engineering Cameras)

Estas cámaras son esenciales para la navegación autónoma y la evitación de obstáculos.

### Hazcams (Hazard Avoidance Cameras)
**Función:** Detectar peligros inmediatos en el camino (rocas, zanjas, dunas) tanto en la parte delantera como trasera del rover. Son fundamentales para la conducción autónoma.
**Ubicación:** Montadas en el chasis, cerca del suelo.

*   **`Frame_FHC1` / `Frame_FHC2`**: Hazcams Frontales Izquierda/Derecha (Par A).
*   **`Frame_FHC3` / `Frame_FHC4`**: Hazcams Frontales Izquierda/Derecha (Par B - Respaldo).
*   **`Frame_RHC1` / `Frame_RHC2`**: Hazcams Traseras Izquierda/Derecha.

### Navcams (Navigation Cameras)
**Función:** Tomar imágenes panorámicas gran angular del terreno circundante. Ayudan a los operadores y al software de navegación a planificar rutas seguras a largas distancias.
**Ubicación:** En la cabeza del mástil (Remote Sensing Mast - RSM), proporcionando una vista elevada similar a la de un humano.

*   **`Frame_NCL`**: Navcam Izquierda.
*   **`Frame_NCR`**: Navcam Derecha.

---

## 2. Cámaras Científicas (Science Cameras)

Estas cámaras se utilizan para realizar investigaciones científicas, analizar la geología y buscar signos de vida microbiana antigua.

### Mastcam-Z
**Función:** El sistema principal de "ojos" del rover. Son cámaras zoom a color y estereoscópicas capaces de tomar video HD, panorámicas y fotos en 3D de la superficie marciana.
**Ubicación:** En la cabeza del mástil (RSM), separadas para visión estereoscópica.

*   **`Frame_MCL`**: Mastcam-Z Izquierda (Zoom).
*   **`Frame_MCR`**: Mastcam-Z Derecha (Zoom).

### SuperCam
**Función:** Analiza la composición química y mineralogía de rocas y suelo a distancia disparando un láser. Incluye una cámara de alta resolución para dar contexto a los disparos del láser.
**Ubicación:** En la cabeza del mástil (RSM).

*   **`Frame_SCRMI`**: Remote Micro-Imager (RMI). Proporciona imágenes detalladas para el análisis químico.

---

## 3. Cámaras del Brazo Robótico (Turret)

Estas cámaras están montadas en la torreta al final del brazo robótico de 2 metros, permitiendo acercarse mucho a los objetivos.

### SHERLOC & WATSON
**Función:** El instrumento SHERLOC utiliza espectrómetros para detectar orgánicos y químicos. WATSON es una cámara gran angular que actúa como una "lupa de geólogo" para tomar imágenes de texturas de rocas a muy corta distancia.
**Ubicación:** En la torreta del brazo robótico.

*   **`Frame_WATSON`**: (Wide Angle Topographic Sensor for Operations and eNgineering). Cámara de acercamiento para texturas finas.
*   **`Frame_SHERLOC`**: Context Imager (ACI). Cámara de contexto para el instrumento SHERLOC.

### PIXL
**Función:** El instrumento PIXL utiliza un espectrómetro de fluorescencia de rayos X para determinar la composición elemental fina de los materiales de superficie.
**Ubicación:** En la torreta del brazo robótico.

*   **`Frame_PIXL`**: Micro Context Camera (MCC). Proporciona imágenes de contexto para ver exactamente dónde el haz de rayos X está analizando la roca.
