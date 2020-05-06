<?php

class NewsNodeCest {

  protected $terms = ['Term 1', 'Term 2', 'Term 3', 'Term 4'];

  protected $vocab = 'Topics';


  /**
   * Create taxonomy terms for testing.
   */
  protected function testCreateTaxonomyTerms(\AcceptanceTester $I, array $terms, $vocab) {
    foreach ($terms as $term) {
      $I->createEntity([
        'name' => $term,
        'vid' => $vocab,
      ], 'taxonomy_term');
    }
  }

  public function testNewsNode(\AcceptanceTester $I){

    $node = $I->createEntity([
      'type' => 'stanford_news',
      'title' => 'News Story',
      //can't create terms before they exist.
      //'su_news_topics' => ['Term 1', 'Term 2', 'Term 3', 'Term 4'],
      'su_news_headline' => 'This is a headline',
      'su_news_dek' => 'This is a dek',
      'su_news_byline' => 'This is a byline',
      'su_news_source' => ['uri' => 'https://test.com', 'title' => 'link text'],
      //'featured_media' => This needs figured out,
      'su_news_featured_media_caption' => 'Featured media caption',
      //'su_news_components' Not sure how to add paragraph type with codeception,
      //'publishing_date' => '06/01/2020 12:00:00A',
      //'url_alias' => '/news/news-story'
    ]);
    $I->amOnPage("/node/{$node->id()}/edit");
    $I->see('Topics');
    $I->fillField('//input@name=su_news_topics[0][target_id]', 'Term 1');
    $I->canSee('This is a headline', '.su-news-headline');

  }

}
