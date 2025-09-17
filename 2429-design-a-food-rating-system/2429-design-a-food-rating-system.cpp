
class Food {
public:
    int foodRating;
    string foodName;

    Food(int food_rating, string food_name) {
        foodRating = food_rating;
        foodName = food_name;
    }

    // Comparator for priority_queue
    bool operator<(const Food& other) const {
        if (foodRating == other.foodRating) {
            return foodName > other.foodName; // lexicographically smaller is higher priority
        }
        return foodRating < other.foodRating; // higher rating first
    }
};

class FoodRatings {
    unordered_map<string, int> rating_mp; // food -> rating
    unordered_map<string, string> foodToCuisine; // food -> cuisine
    unordered_map<string, priority_queue<Food>> cuisineToFoods; // cuisine -> max heap of foods

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            rating_mp[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToFoods[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        rating_mp[food] = newRating;
        string cuisineName = foodToCuisine[food];
        cuisineToFoods[cuisineName].push(Food(newRating, food));
    }

    string highestRated(string cuisine) {
        auto& pq = cuisineToFoods[cuisine];
        Food topFood = pq.top();
        while (rating_mp[topFood.foodName] != topFood.foodRating) {
            pq.pop();
            topFood = pq.top();
        }
        return topFood.foodName;
    }
};

/**
 * Example usage:
 * vector<string> foods = {"sushi", "ramen", "taco"};
 * vector<string> cuisines = {"japanese", "japanese", "mexican"};
 * vector<int> ratings = {5, 7, 8};
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating("ramen", 9);
 * cout << obj->highestRated("japanese") << endl;
 */
