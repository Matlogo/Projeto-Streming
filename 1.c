 serie = (Serie*) malloc(sizeof(Serie) * 259);  //aloca memória pro vetor struct de séries

    getmaxyx(stdscr, yterminal, xterminal);  //consegue os valores máximos de resolução do terminal
    
    arquivotexto = fopen("streaming_db.txt", "r");
    arquivobinSeries = fopen("arquivobinSeries.dat", "rb");
    arquivobinHistorico = fopen("arquivobinHistorico.dat", "rb");
    
    borda = newwin(yterminal - 7, xterminal - 7, 4, 4);
    
    getmaxyx(borda, yborda, xborda);  //consegue as dimensões da janela de borda

    WINDOW *EntradaInfo = newwin(3, xborda - 30, yterminal / 2, (xterminal - (xborda - 30)) / 2);

    for (int i = 0; i < QuantidadeSeries; i++)
    {
        serie[i].QuantidadeEpisodiosTotais = 0;

        fread(&serie[i].id, sizeof(int), 1, arquivobinSeries);
        fread(serie[i].Nome, sizeof(char), 101, arquivobinSeries);
        fread(serie[i].Genero, sizeof(char), 41, arquivobinSeries);
        fread(&serie[i].Classificacao, sizeof(int), 1, arquivobinSeries);
        fread(serie[i].Plataforma, sizeof(char), 41, arquivobinSeries);
        fread(&serie[i].DuracaoMediaEpisodios, sizeof(int), 1, arquivobinSeries);
        fread(&serie[i].QuantidadeTemporadas, sizeof(int), 1, arquivobinSeries);

        int realoca = serie[i].QuantidadeTemporadas;
        serie[i].QuantidadeEpisodiosPorTemporada = (int*) malloc(realoca * sizeof(int));
        
        for (int j = 0; j < serie[i].QuantidadeTemporadas; j++) {

            fread(&serie[i].QuantidadeEpisodiosPorTemporada[j], sizeof(int), 1, arquivobinSeries);
      
            serie[i].QuantidadeEpisodiosTotais=serie[i].QuantidadeEpisodiosTotais+serie[i].QuantidadeEpisodiosPorTemporada[j];
        
        }//for

    }//for
