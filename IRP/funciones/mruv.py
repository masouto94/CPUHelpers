from fisica import kmh_a_ms
print()
print(kmh_a_ms(61)/8)
#MRUV

gabriel = 3
florencia = 2
mts_gabriel = 10
mts_florencia= 0

for i in range(100):
    print(f"Gabriel va a {gabriel} m/s lleva {mts_gabriel} metros recorridos al segundo {i}")
    print(f"Florencia va a {round(float(florencia),3)} m/s lleva {round(float(mts_florencia),3)} metros recorridos al segundo {i}")
    if mts_florencia >= mts_gabriel:
        print("####")
        print(f"Florencia lo alcanzó para el segundo {i}")
        print("####")
        break
    mts_gabriel += gabriel
    mts_florencia += florencia
    florencia += 0.4