use std::{collections::{HashMap, BTreeSet}, cmp::Reverse};

struct FoodRatings {
    food_rating : HashMap<String, i32>,
    cuisine_foods : HashMap<String, BTreeSet<(Reverse<i32>, String)>>,
    food_cuisine : HashMap<String, String>
}


/** 
 * `&self` means the method takes an immutable reference.
 * if you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings {

    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut food_rating = HashMap::new();
        let mut cuisine_foods: HashMap<String, BTreeSet<(Reverse<i32>, String)>>  = HashMap::new();
        let mut food_cuisine = HashMap::new();

        for (food, &rating) in foods.iter().zip(ratings.iter()){
            food_rating.insert(food.clone(), rating);
        }

        for (food_index, cuisine) in cuisines.iter().enumerate(){
            let food = foods[food_index].clone();
            let rating = *food_rating.get(&food).unwrap();
            let food_packet = (Reverse(rating), food.clone());

            cuisine_foods.entry(cuisine.clone())
                .and_modify(|x| {x.insert(food_packet.clone());})
                .or_insert(BTreeSet::from([food_packet]));


            food_cuisine.insert(food, cuisine.clone());
        }
        
        
        Self{
            food_rating,
            cuisine_foods,
            food_cuisine
        }
    }
    
    fn change_rating(&mut self, food: String, new_rating: i32) {
        let old_rating = *self.food_rating.get(&food).unwrap();
        let food_packet = (Reverse(old_rating), food.clone());
        let cuisine = self.food_cuisine.get(&food).unwrap();
        
        if let Some(x) = self.cuisine_foods.get_mut(cuisine){
            x.remove(&food_packet);
            x.insert((Reverse(new_rating), food.clone()));
            self.food_rating.insert(food, new_rating);
        } 
    }
    
    fn highest_rated(&self, cuisine: String) -> String {
        let item = self.cuisine_foods.get(&cuisine).unwrap().iter().min().unwrap();
        item.1.clone()
    }
}
