
from cmath import sin


with open ("test.txt", "w") as sinusoida:
    sinusoida.write("constexpr int8_t sin_array[SIN_ARRAY_LEN] = { ")
    for i in range(0, 126):
        sinusoida.write(f"{int(100 * sin( i / 20).real)}, ")
    sinusoida.write("};")