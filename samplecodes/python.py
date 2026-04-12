class UserService:
    def __init__(self, repository):
        self.repository = repository

    def find_by_email(self, email: str):
        if not email or not isinstance(email, str):
            raise ValueError("Invalid email provided")

        user = self.repository.find_by_email(email)
        return None if user and user.is_deleted else user

    def get_active_users(self):
        return [
            {
                "id": user.id,
                "name": user.name,
                "role": user.role or "guest"
            }
            for user in self.repository.find_all()
            if user.is_active
        ]

    def load_config(self, path="./config.json"):
        try:
            with open(path, "r") as f:
                return f.read()
        except Exception as error:
            print(f"Failed to load config: {error}")
            return None


service = UserService(None)

for user in service.get_active_users():
    print(f"{user['name']} ({user['role']})")