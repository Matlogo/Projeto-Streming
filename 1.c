void lerSeries(Serie *serie, int QuantidadeSeries, FILE *arquivo) {

    for (int i = 0; i < QuantidadeSeries; i++) 
    {
        serie[i].QuantidadeEpisodiosTotais = 0;

        fscanf(arquivo, "%d,", &serie[i].id);
        fscanf(arquivo, "%[^,\n],", serie[i].Nome);
        fscanf(arquivo, "%[^,\n],", serie[i].Genero);
        fscanf(arquivo, "%d,", &serie[i].Classificacao);
        fscanf(arquivo, "%[^,\n],", serie[i].Plataforma);
        fscanf(arquivo, "%d,", &serie[i].DuracaoMediaEpisodios);
        fscanf(arquivo, "%d,", &serie[i].QuantidadeTemporadas);

        int realoca = serie[i].QuantidadeTemporadas;
        serie[i].QuantidadeEpisodiosPorTemporada = (int*) malloc(realoca * sizeof(int));
                                                                                        
        for (int j = 0; j < serie[i].QuantidadeTemporadas; j++) {

            fscanf(arquivo, "%d,", &serie[i].QuantidadeEpisodiosPorTemporada[j]);
      
            serie[i].QuantidadeEpisodiosTotais=serie[i].QuantidadeEpisodiosTotais+serie[i].QuantidadeEpisodiosPorTemporada[j];
        }//for
    }//for
}//void lerseries
