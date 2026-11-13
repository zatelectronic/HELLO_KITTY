// Hello Kitty — Zat Electronic — exemplo de pisca-pisca (6 LEDs)
// J1: GND -> pino 1; LED1..LED6 (pinos 2..7) -> Arduino D8..D13
const int LED[] = {8, 9, 10, 11, 12, 13};
const int N = 6;

void todos(int v) { for (int i = 0; i < N; i++) digitalWrite(LED[i], v); }

void setup() {
  for (int i = 0; i < N; i++) { pinMode(LED[i], OUTPUT); digitalWrite(LED[i], LOW); }
  randomSeed(analogRead(A0));
}

void corrida(int t) {
  for (int i = 0; i < N; i++) { digitalWrite(LED[i], HIGH); delay(t); digitalWrite(LED[i], LOW); }
  for (int i = N - 2; i > 0; i--) { digitalWrite(LED[i], HIGH); delay(t); digitalWrite(LED[i], LOW); }
}

void alternado(int vezes, int t) {
  for (int k = 0; k < vezes; k++) {
    for (int i = 0; i < N; i++) digitalWrite(LED[i], (i + k) % 2);
    delay(t);
  }
  todos(LOW);
}

void aleatorio(int vezes, int t) {
  for (int k = 0; k < vezes; k++) {
    int i = random(N);
    digitalWrite(LED[i], HIGH); delay(t); digitalWrite(LED[i], LOW);
  }
}

void preencher(int t) {
  for (int i = 0; i < N; i++) { digitalWrite(LED[i], HIGH); delay(t); }
  delay(t * 3);
  for (int i = N - 1; i >= 0; i--) { digitalWrite(LED[i], LOW); delay(t); }
}

void loop() {
  corrida(70);
  alternado(10, 250);
  aleatorio(30, 80);
  preencher(90);
}
