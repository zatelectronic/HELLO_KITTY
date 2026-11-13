# HELLO_KITTY — revisão R01 (2026-11-12)

Organização no padrão Zat Electronic (KiCad 10). Titular: **Zat Electronic**.

## O que mudou
1. **Arquivos sem espaço**: `HELLO KITTY.kicad_*` → `HELLO_KITTY.kicad_*`; `packages3D/` sem espaços nos nomes.
2. **Esquemático hierárquico**: capa A2 temática (blocos, **mapa dos LEDs** com a posição real e a cor de cada LED, vista 3D) + 2 folhas A4:
   02 LEDS (D1–D6, R1–R6) · 03 CONN (J1).
   Sinais entre folhas por global label: LED1 … LED6.
3. **Reanotação**: LEDs **L → D** (padrão doc 03); LED Dn = canal n.
4. **Bibliotecas só globais** (KiCad 10 primeiro, ZAT depois), sem pasta lib:
   - `power:GND` no lugar do GND SparkFun;
   - `ZAT_Connector:Conn_01x07` + footprint `PinHeader_1x07_P2.54mm_RightAngle_EdgeMount` (3D barra 90°);
   - LEDs `ZAT_LED:LED_D5.0mm_<cor>` (3D na cor real) e resistores `ZAT_Resistor_THT:…_220R`.
5. **Campos padronizados**: Value, Footprint, Description (PT), Stock Code, Package Group.
6. **PWR_FLAG do GND** sobre o fio real (pino 1 do J1).
7. **PCB revinculado** ao esquema novo (posições dos pads intactas, mesmas nets).
8. **Arte da serigrafia**: todos os logos G*** + linhas/moldura da placa viraram **um único footprint LOGO** (board only, fora da BOM/CPL) com **courtyard**; a arte foi **recortada em volta de cada componente** (courtyard + 0,30 mm) — some a tinta sobre pad/serigrafia dos LEDs (autorizado).
9. **Roteamento**: 6 trilhas novas B.Cu 1 mm J1 pinos 2–7 → R1–R6 pino 1, igual ao EMICIDA (autorizado). Antes ficavam 6 ligações abertas.
10. **Referências visíveis 1,0 mm**: na frente onde há espaço; D2 na B.SilkS (espelhada) por falta de espaço / ambiguidade na frente.
11. **README** reescrito (pinagem, correntes, BOM) + firmware em `firmware/HELLO_KITTY/`.

## Conferências feitas aqui
- ERC simulado: 0 erros · conectividade esquema × PCB: 0 diferenças.
- Serigrafia × serigrafia / pads / borda: 0 · courtyards sobrepostos: 0.
- Cobre: clearances ok, GND numa ilha só com a zona preenchida.

## Fazer no KiCad
1. Abrir o PCB → **B** (repreencher zonas) → salvar.
2. Rodar **ERC** e **DRC** e conferir 0/0.
3. Vista 3D: conferir os modelos (variáveis `ZAT_3D` / `ZAT_ARDUINO_3D`).

## R01.1 (2026-11-13) — sobre os arquivos devolvidos pelo Kenneth
- Partiu dos arquivos editados pelo Kenneth (posições das referências mantidas).
- **Serigrafia da arte sem fendas**: na R01 os desenhos tinham sido divididos com fendas de 0,02 mm (fp_poly não tem furo) e apareciam traços pretos. Agora cada desenho com furo é um polígono único "fraturado" (ponte de largura zero, igual ao conversor de imagem do KiCad) — sem nenhum traço faltando. Área de serigrafia conferida = área da arte recortada.
- Recorte da arte também respeita as referências visíveis que o Kenneth posicionou.
- Conferências: serigrafia × serigrafia/pads 0 · courtyards 0 · esquema × PCB 0 diferenças · ERC 0.
