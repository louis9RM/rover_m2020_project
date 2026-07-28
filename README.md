# Rover Autónomo M2020 — Navegación y Evitación de Obstáculos en ROS 2

> Sistema de control para navegación autónoma con evitación reactiva de obstáculos, desarrollado en **ROS 2 / C++** sobre el modelo del rover Perseverance (NASA/JPL). Implementado con **Arquitectura Hexagonal (Ports & Adapters)**, lo que permite intercambiar sensores y simuladores (Gazebo, Isaac Sim) sin tocar la lógica de navegación.

<!-- [PON AQUÍ UNA IMAGEN O GIF del rover en el simulador.
     Sube el archivo a una carpeta docs/ y enlázalo así:
     ![Rover en simulación](docs/rover_sim.png) ] -->

---

## Relevancia para automatización minera

Un rover navegando terreno irregular y evitando obstáculos resuelve **el mismo problema de ingeniería que un vehículo autónomo en una operación minera** (camiones de acarreo, equipos de exploración): percepción del entorno, detección de peligros y control de tracción en terreno no estructurado.

Este proyecto demuestra competencias directamente aplicables a **vehículos autónomos y sistemas de percepción en minería**:

- **Percepción con LIDAR** para detección de obstáculos en tiempo real.
- **Lógica de seguridad / evitación de peligros** (parar y maniobrar ante obstáculos cercanos), análoga a los sistemas anticolisión de flotas autónomas.
- **Arquitectura desacoplada** que permite portar el mismo software entre distintos sensores y plataformas — clave en entornos industriales heterogéneos.

---

## Arquitectura

El proyecto aplica **Arquitectura Hexagonal** para separar la lógica de negocio del hardware y del simulador:

```
rover_ports          → Interfaces (contratos): IDistanceSensor, IMotorControls
        ▲
rover_core           → Lógica de dominio: RoverNavigator (decisión de navegación)
        ▲
rover_infrastructure → Adaptadores concretos:
                         · GazeboLidarAdapter  (LIDAR real vía /scan)
                         · IsaacDepthAdapter   (cámara de profundidad)
                         · SimMotorAdapter     (motores vía /cmd_vel)
        ▲
rover_bootstrap      → Ensamblado e inyección de dependencias + bucle de control (10 Hz)
```

**Por qué importa:** la lógica de navegación (`rover_core`) no conoce si el sensor es un LIDAR de Gazebo o una cámara de Isaac Sim. Se le inyecta a través de interfaces. Cambiar de simulador o de sensor **no requiere modificar la lógica**, solo agregar un adaptador. Es el mismo principio que se usa para llevar software de un entorno de prueba a un equipo real.

---

## Lógica de navegación

`RoverNavigator` ejecuta un ciclo de control reactivo a 10 Hz:

1. Lee la distancia de todos los sensores registrados.
2. Si algún sensor detecta un obstáculo a menos de **1 metro** → detiene el rover y gira para maniobrar.
3. Si el camino está libre → avanza al frente.

Es una estrategia de **evitación reactiva de obstáculos** (no planificación global de rutas), diseñada como base extensible.

---

## Sensores y percepción

- **LIDAR (Gazebo):** el adaptador se suscribe al tópico `/scan` (`sensor_msgs/LaserScan`) y calcula la distancia mínima al obstáculo más cercano. **Funcional.**
- **Modelo del rover:** URDF completo del Perseverance con chasis, sistema rocker-bogie, 6 ruedas con dirección, mástil (RSM) y brazo robótico, más las cámaras de ingeniería (Hazcams, Navcams) documentadas en [`urdf/CAMERAS_INFO.md`](urdf/CAMERAS_INFO.md).
- **Detección visual:** modelo YOLOv8 incluido para experimentos de detección de objetos.

---

## Estado del proyecto

Transparencia sobre qué está funcional y qué está en desarrollo:

| Componente | Estado |
| --- | --- |
| Arquitectura hexagonal (ports/core/infra/bootstrap) | ✅ Implementada |
| Adaptador LIDAR (Gazebo) | ✅ Funcional |
| Lógica de evitación reactiva | ✅ Funcional |
| Control de motores (`/cmd_vel`) | ✅ Funcional |
| Adaptador de profundidad (Isaac Sim) | 🚧 Interfaz lista, valor mockeado — integración en curso |
| Detección con YOLOv8 en el pipeline | 🚧 Modelo incluido, integración en curso |
| Planificación global de rutas | ⬜ Trabajo futuro |

---

## Stack técnico

- **ROS 2** (C++, `rclcpp`)
- **Arquitectura Hexagonal / Ports & Adapters**, inyección de dependencias
- **Gazebo** e **Isaac Sim / Omniverse** (modelos `.usd`)
- **LIDAR** (`sensor_msgs/LaserScan`), control por `geometry_msgs/Twist`
- **YOLOv8** para detección de objetos
- Modelo URDF del rover Perseverance (NASA/JPL, recurso público)

---

## Estructura del repositorio

```
├── ros2_ws/src/
│   ├── rover_ports/          Interfaces (contratos de sensores y motores)
│   ├── rover_core/           Lógica de navegación (dominio)
│   ├── rover_infrastructure/ Adaptadores: Gazebo LIDAR, Isaac, motores
│   └── rover_bootstrap/      Main, inyección de dependencias, bucle de control
├── urdf/                     Modelo del rover (URDF + USD) y doc de cámaras
├── meshes/ textures/         Geometría y texturas del rover
└── mapa.usdc                 Escenario de simulación
```

---

## Autoría

**Ever Ramos** — Ingeniero Electrónico (UNI) · M.Sc. Ingeniería de Software (UNMSM)

Diseño e implementación del **sistema de navegación, la arquitectura de software y la integración en ROS 2**. El modelo 3D del rover Perseverance es un recurso público de la NASA/JPL, usado como base física de la simulación.
