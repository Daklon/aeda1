class Cell{

    private:
        bool lastState;
        bool currentState;
	int xPosition;
	int yPosition;
        bool isAlive();
    public:
        Cell(int x, int y);
        ~Cell();	
	bool getState();
	void setUpdated();
};
