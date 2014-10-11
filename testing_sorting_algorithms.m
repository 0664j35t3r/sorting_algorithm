%**************************************************************************
%
% Laufzeitanalyses von Sortieralgorithmen:
%   
%   InsertionSort (Sortieren durch Einfuegen)
%   MinSort (Sortieren durch das Finden der kleinsten Zahl)
%   BubbleSort (Sortieren durch das Tauschen benachbarter Zahlen)
%
%
% 
%**************************************************************************

function TestSortingAlgorithms()
clear all;
close all;

    %Vorimplementierte Algorithmen
    numMethods = 3;
    legendText = {'insert', 'min', 'bubble'};
    funcHnds = {@insertionSort, @minSort, @bubbleSort};
    flgCheckCorrectness = 1;
    
    %Data
    numSamples = 6;
    numRuns = 10;
    n = round(logspace(3,5,numSamples));     %y = logspace(a,b,n) generates n points between decades 10^a and 10^b.
    runTimeMean = zeros(numMethods,numSamples);
    runTimeStd = zeros(numMethods,numSamples);
    
    %Misc
    dbstop if error                          %this command is very usefull to locate mistakes, try also dbup and dbdown
    
    
     
    for sizeId = 1:length(n)
        runTimes = zeros(numMethods, numRuns);
        for runId = 1:numRuns
            rand('seed', runId*length(n) + sizeId + sum(100*clock));
            A = generateTestData(n(sizeId));
            
            %**************************************************************
            %* Evalute the algorithms
            %**************************************************************
            for algId = 1:numMethods
                tic  
                [Aout] = funcHnds{algId}(A); 
                runTimes(algId,runId) = toc;
                if flgCheckCorrectness
                    if sum(Aout == sort(A)) ~= n(sizeId)
                        error(['Implementation of the algorithm <' legendText{algId} '> is wrong!']);
                    end
                end
            end

        end
        
        runTimeMean(:,sizeId) = mean(runTimes,2);
        runTimeStd(:,sizeId) = std(runTimes,1,2);

    end

    % plot the results
    plotResults(runTimeMean, runTimeStd, n, numMethods, legendText)
end

function A = generateTestData(n)
    A = round(1000*rand(1,n));
end

function plotResults(runTimeMean, runTimeStd, n, numMethods, legendText)

    colors = lines(numMethods);
    lhnd = zeros(1,numMethods);
    hfig=figure; hold all;
    for i=1:numMethods
        l=shadedErrorBar(n, runTimeMean(i,:), runTimeStd(i,:),{'color', colors(i,:), 'linewidth', 2});
        lhnd(i) = l.mainLine;
    end

    l=legend(lhnd, legendText,'location','northwest');
    set(l,'fontsize',24);
    set(gca, 'fontsize',28);
    xlabel('n', 'fontsize',28);
    ylabel('T(n) in sec', 'fontsize',28);
    set(hfig,'Color','white');
    print('-depsc',  [pwd '/results.eps']); 
end


%**************************************************************
%* Implementierungen
%**************************************************************

function [A] = insertionSort(A)
    n = length(A);
    for i=2:n
       h = A(i);                    %Hilfsvariable h
       j = i-1;                     %Vergleichsindex j lÃ¤uft von i-1 bis 1
       while j > 0 && h < A(j)      %Vergleiche h mit jeder mit kleinerem Index
                                    %wichtig index > 0 Vergleich muss
                                    %zuerst erfolgen
           A(j+1) = A(j);           %verschiebe x nach rechts
           j = j - 1; 
       end
       A(j+1) = h;                  %Tausche h mit der letzten Zahl mit der verglichen wurde
    end
end

function [A] = minSort(A) 
    n = length(A);
    for i=1:n-1                     %n-1 da das min zuletzt in A(n-1:n) gesucht wird
       minVal = A(i);               %Hilfsvariable fÃ¼r den minimalen Wert
       minId = i;                   %Hilfsvariable fÃ¼r den minimalen Index
       for j=i+1:n                  %i+1 da minVal = A(i) 
           if A(j) < minVal         %Minimum suchen
               minVal = A(j);
               minId = j;
           end
       end
       A(minId) = A(i);             %Tausche A(i) mit dem Minimum
       A(i) = minVal;
    end
end

function [A] = bubbleSort(A)
    n = length(A);
    flgIsSorted = 0;                %Variable fÃ¼r die Abbruchbedingung
    while flgIsSorted < 1           %Durchlaufe das Feld bis es sortiert ist
        flgIsSorted = 1;            %Wir nehmen an das Feld ist sortiert
        for i=1:n-1                 %Vergleiche je 2 benachbarte Elemente
            if A(i) > A(i+1)        %Vertausche diese falls nÃ¶tig
                h = A(i);
                A(i) = A(i+1);
                A(i+1) = h;
                flgIsSorted = 0;    %Das Feld ist noch nicht sortiert
            end                     %Nun steht die grÃ¶ÃŸten Zahlen am Ende des Feldes
        end
        n = n-1;                    %Das zu durchsuchende Feld ist um ein Element kleiner im nÃ¤chsten Durchlauf
    end
end
