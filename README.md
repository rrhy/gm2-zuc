# gm2-zuc #
## introduce ##
use gm2 and zuc for encryption and decryption.

recommand gm2 for keys exchange, and zuc for stream encryption and decryption.

## compile ##
manual compile

```
$>cd gm_crypto
$>make
$>cp libzgmssl.lib
$>cd ..
$>make
````
or use shell

`
$>sh gen.sh
`

## test result ##
```
in len = 50
zin: 68656C6C6F20746869732069732074686520666972737420737472696E672C2075736520736D3220746F20656E6372797074
zen: 2AE50DA2234D1BA7B0D0BFF435D2C364EFB1F7BE15A4096A75E0C592DE07F016299C12D54FF145C13E559421C239F56C7844
zde: 68656C6C6F20746869732069732074686520666972737420737472696E672C2075736520736D3220746F20656E6372797074

tstring: 68656C6C6F20746869732069732074686520666972737420737472696E672C2075736520736D3220746F20656E6372797074

ciphertext: 30819B022040159CD4671161D14516C7E54A1D854ECA39FD8392F17CEF60DDC8C93D4D64AC022100A4638FEBFAD7647AC
4387C3F3446B9CC6212FB04126A542613878ECA0959B1A90420190CFF724307D74A24A68F78E2F3DAC7149FD7CD366A96C60630E6076A
0543D8043207D0CD27B0719B814CE5892C83A2578FA1A7E6148E4EE229FA6AD8A1FCAA0275A882CECA3844CC4DE4C5F2E52895D0223569

t_out: 68656C6C6F20746869732069732074686520666972737420737472696E672C2075736520736D3220746F20656E6372797074
```