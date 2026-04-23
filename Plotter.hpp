#ifndef PLOTTER_HPP
#define PLOTTER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cstdio> 

class Plotter {
private:
    std::string title;
    std::vector<int> x_vals;
    std::vector<double> y_vals;

public:
    Plotter(const std::string& plotTitle) : title(plotTitle) {}

    void addData(int n, double time) {
        x_vals.push_back(n);
        y_vals.push_back(time);
    }

    void plot() {
        std::cout << "[Plotter] Gerando grafico para '" << title << "'...\n";

        FILE* pipe = popen("python3", "w");
        if (!pipe) {
            std::cerr << "Erro: Nao foi possivel iniciar a comunicacao com o Python.\n";
            return;
        }

        fprintf(pipe, "import matplotlib.pyplot as plt\n");

        fprintf(pipe, "x = [");
        for (int val : x_vals) fprintf(pipe, "%d,", val);
        fprintf(pipe, "]\n");

        fprintf(pipe, "y = [");
        for (double val : y_vals) fprintf(pipe, "%f,", val);
        fprintf(pipe, "]\n");

        fprintf(pipe, "plt.figure(figsize=(8, 5))\n");
        fprintf(pipe, "plt.plot(x, y, marker='o', color='#1f77b4', linewidth=2)\n");
        fprintf(pipe, "plt.title('%s')\n", title.c_str());
        fprintf(pipe, "plt.xlabel('Tamanho da Entrada (n)')\n");
        fprintf(pipe, "plt.ylabel('Tempo Medio (ms)')\n");
        fprintf(pipe, "plt.grid(True, linestyle='--', alpha=0.6)\n");

        std::string filename = title;
        for (char& c : filename) { if (c == ' ') c = '_'; }
        fprintf(pipe, "plt.savefig('grafico_%s.png', dpi=300, bbox_inches='tight')\n", filename.c_str());
        
        pclose(pipe);
        std::cout << "[Plotter] Sucesso! Salvo como 'grafico_" << filename << ".png'\n";
    }
};

#endif