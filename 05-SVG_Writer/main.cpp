#include "AllocateStatistics.h"
#include "Figure.h"

void Run()
{
  Figure figure = loadFigure("figure.txt");
  ShapeCount count = countShapes(figure);
  std::cout << "Circles: " << count.circles << "\nLines: " << count.lines << std::endl;
  renderFigure(figure, "figure.svg");
  alloc_tracker.Dump();                             // show stats
}

int main()
{
	Run();
	// Stop memory tracking and write the graph file now
//	alloc_tracker.StopTracking();
//	alloc_tracker.DumpPeaks();
	alloc_tracker.WriteGraph();
	return EXIT_SUCCESS;
}
