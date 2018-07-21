
//  CONTROL

bool lineTracking = false;      // Will the robot track lines?
bool obstacleAvoidance = true;  // Will the robot avoid obstacles? (RECCOMENDED)
bool bluetoothControl = true;   // Will the robot accept bluetooth control? (WASD controls)
bool infraredControl = false;   // Will the robot accept infrared control? (NOT RECCOMENDED)

bool prioritizeUser = false;    // Will the user be able to override the obstacle/line tracking controls?
bool prioritizeAvoid = true;    // Will the obstacle avoidance system be able to override the user input/line tracking? (RECCOMENDED)
bool priortitizeLine = false;   // Will the line tracking system override user input and obstacle avoidance?
// NOTE: If you select more than one, the prioritizations are prioritzed from top to bottom (as listed)


//  MOTORS

bool tweenMotors = true;        // When the robot changes speed, will it change smoothly, or instantly go the right speed? (RECCOMENDED)
bool tweenTurning = true;       // When the robot turns, will it turn smoothly, or instantly turn the right direction? (RECCOMENDED)
// NOTE: If tweenturning is disabled, It won't rutn easily.



//
