<?php

/**
 * Class NewsNodeCest
 */
class NewsNodeCest {

  /**
   * News node creation and editing.
   */
  public function testNewsNode(\AcceptanceTester $I) {
    $I->logInWithRole('administrator');
    $term = $I->createEntity([
      'name' => 'Foo',
      'vid' => 'stanford_news_topics',
    ], 'taxonomy_term');
    $node = $I->createEntity([
      'type' => 'stanford_news',
      'title' => 'News Story',
      'su_news_headline' => 'This is a headline',
      'su_news_dek' => 'This is a dek',
      'su_news_byline' => 'This is a byline',
      'su_news_source' => [
        'uri' => 'http://google.com',
        'title' => 'link text',
      ],
      'su_news_featured_media_caption' => 'Featured media caption',
      'su_news_topics' => $term->id(),
      'su_news_publishing_date' => date('Y-m-d'),
    ]);
    $I->amOnPage($node->toUrl()->toString());
    $I->canSee('This is a headline', 'h1');

    $I->amOnPage('/news');
    $I->canSee('This is a headline', 'h2');
    $I->canSee(date('F j, Y'));

    $I->click('Foo', '.menu-block');
    $I->canSee('This is a headline', 'h2');
    $I->canSee(date('F j, Y'));

    $I->logInWithRole('authenticated');
    $I->amOnPage('/news');

    $I->click('This is a headline');
    // We can't get the new domain from codeception, so we just check if the
    // destination was redirected.
    $I->canSeeCurrentUrlEquals('/');
  }

}
